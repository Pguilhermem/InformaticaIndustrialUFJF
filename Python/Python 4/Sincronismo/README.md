# Aula 4: Sincronismo

Dois exemplos sobre threads. O `exemplo_threads.py` executa a mesma contagem duas vezes, primeiro em sequência e depois em duas threads, e compara o tempo gasto. O `exemplo_lock.py` simula quatro transferências simultâneas numa conta bancária e usa um `Lock` para que elas não se atrapalhem ao alterar o saldo.

## Como funcionam as threads

Uma thread é uma linha de execução dentro de um programa. Todo programa começa com uma, a thread principal, e pode criar outras que executam funções ao mesmo tempo que ela:

```python
t1 = threading.Thread(target=contador, args=(0, 5), name='T1')
t2 = threading.Thread(target=contador, args=(5, 10), name='T2')
t1.start()     # T1 começa a executar contador(0, 5)
t2.start()     # T2 começa logo em seguida, sem esperar T1
t1.join()      # a thread principal espera T1 terminar
t2.join()      # e depois espera T2
```

- `target` é a função que a thread executa, e `args`, a tupla de argumentos dela.
- `start()` inicia a thread e retorna na hora.
- `join()` faz a thread que o chamou esperar até a outra terminar. Sem os `join`, o `print` do tempo gasto rodaria antes de as contagens acabarem.

No `exemplo_threads.py`, cada número da contagem espera 0,2 s com `time.sleep`. Em sequência, as duas contagens de 5 números somam cerca de 2 s. Com threads, as esperas acontecem ao mesmo tempo e o total cai para cerca de 1 s. Os números de T1 e T2 aparecem intercalados na saída, numa ordem que pode mudar a cada execução.

No Python, as threads aceleram o programa quando ele passa tempo **esperando**: `sleep`, rede, leitura de arquivos. Para cálculos pesados, que usam o processador o tempo todo, elas não executam de fato em paralelo, por causa do GIL (Global Interpreter Lock) do interpretador.

## Como funciona o `Lock`

Quando várias threads leem e alteram o mesmo dado, o resultado pode depender da ordem em que elas executam. Isso é uma **condição de corrida**. No `exemplo_lock.py`, cada transferência faz três passos:

```python
saldo_atual = self.saldo        # 1. lê o saldo
saldo_atual -= valor            # 2. calcula o novo saldo
self.saldo = saldo_atual        # 3. grava o novo saldo
```

Sem proteção, as quatro threads leem o saldo de 200 antes de qualquer uma gravar. Cada uma grava `200 - valor`, e o saldo final é o da última a gravar: as outras três transferências se perdem.

O `Lock` resolve isso permitindo que só uma thread por vez execute o trecho protegido. As outras esperam a vez:

```python
with self.lock:
    saldo_atual = self.saldo
    saldo_atual -= valor
    self.saldo = saldo_atual
```

Com o `Lock`, as transferências acontecem uma depois da outra, e o saldo final é sempre 200 − 50 − 70 − 20 − 60 = 0.

Para ver a condição de corrida, apague a linha `with self.lock:` e tire a indentação das linhas de baixo, como indica a docstring da classe `ContaBancaria`.

## Como funciona o `with`

O `with` executa um bloco entre uma ação de entrada e uma de saída. Com um `Lock`, a entrada adquire o lock e a saída o libera:

```python
with self.lock:
    ...             # só uma thread por vez executa aqui
```

É o mesmo que:

```python
self.lock.acquire()
try:
    ...
finally:
    self.lock.release()
```

O `with` garante que o lock é liberado ao sair do bloco, mesmo que aconteça um erro dentro dele. Se o lock nunca fosse liberado, as outras threads ficariam esperando para sempre.

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 4/Sincronismo`:

```bat
python exemplo_threads.py
```

```bat
python exemplo_lock.py
```
