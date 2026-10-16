# Aula 1: Coleções e Loops

Demonstra as coleções básicas do Python e como percorrê-las com laços. O programa cria e altera uma lista, um dicionário e uma tupla, imprimindo o conteúdo de cada um. No fim, usa uma lista como pilha e um `deque` como fila, para mostrar a diferença na ordem em que os elementos saem.

## Como funcionam as coleções

### Lista

Sequência ordenada e alterável, escrita entre colchetes. Cada elemento é acessado pelo índice, que começa em 0:

```python
lista = [1, 2, "Guilherme", 5.5, True, 'a']

lista.append("Soares")   # acrescenta no fim
lista[0] = 55            # troca o elemento da posição 0
```

### Tupla

Sequência ordenada como a lista, mas escrita entre parênteses e **imutável**: depois de criada, não aceita `append` nem troca de elementos.

```python
tupla = (1, 2, "Guilherme", 5.5, True, 'a')
tupla[0] = 55            # erro: TypeError
```

### Dicionário

Coleção de pares chave e valor, escrita entre chaves. O valor é acessado pela chave, não por posição:

```python
dicionario = {"curso": "Informática Industrial", "númeroCréditos": 4}

dicionario["curso"] = "Robótica Móvel"   # chave existente: troca o valor
dicionario["NumeroHoras"] = 60           # chave nova: cria o par
```

### Pilha e fila

Pilha e fila diferem na ordem em que os elementos saem:

- **Pilha:** o último a entrar é o primeiro a sair. Uma lista comum serve: `append` coloca no fim e `pop()` retira do fim.
- **Fila:** o primeiro a entrar é o primeiro a sair. O `deque`, da biblioteca padrão `collections`, retira do início com `popleft()`.

```python
from collections import deque

pilha = []
pilha.append(1)
pilha.append(2)
pilha.pop()        # retira 2

fila = deque()
fila.append(1)
fila.append(2)
fila.popleft()     # retira 1
```

Uma lista também consegue retirar do início com `pop(0)`, mas para isso ela precisa deslocar todos os outros elementos uma posição. O `deque` foi feito para retirar das duas pontas sem esse custo.

## Como funcionam os laços

O `for` percorre os elementos de uma coleção, um por vez:

```python
for x in lista:
    print(x)
```

Para percorrer pelos índices, o `range(inicio, fim)` gera os números de `inicio` até `fim - 1`. A função `len` devolve a quantidade de elementos da coleção:

```python
for x in range(0, len(lista)):   # x vale 0, 1, 2, ... até len(lista) - 1
    if x == 2:
        continue                 # pula o resto do bloco e vai para o próximo x
    print(lista[x])
```

O `continue` interrompe só a repetição atual: o laço segue com o próximo valor.

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 1/Colecoes_e_Loops`:

```bat
python main.py
```

Saída esperada:

```
1
2
Guilherme
5.5
True
a
55
2
5.5
True
a
Soares
{'curso': 'Informática Industrial', 'númeroCréditos': 4}
{'curso': 'Robótica Móvel', 'númeroCréditos': 4, 'NumeroHoras': 60}

1
2
Guilherme
5.5
True
a
9 8 7 6 5 4 3 2 1 0
0 1 2 3 4 5 6 7 8 9
```

A primeira contagem sai em ordem decrescente porque vem da pilha; a segunda sai em ordem crescente porque vem da fila.
