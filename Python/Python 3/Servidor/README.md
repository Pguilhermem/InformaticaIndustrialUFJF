# Aula 3: Servidor

Servidor TCP que funciona como calculadora. Ele aguarda conexões na porta 9000 do próprio computador, recebe expressões matemáticas em texto, como `2+3`, calcula o resultado e o devolve ao cliente. O cliente que conversa com ele está na pasta [`Python 3/Cliente`](../Cliente/README.md).

A classe `Servidor`, em `servidor.py`, usa atributos com `_` e `__` e docstrings, explicados em [`Python 2/POO`](../../Python%202/POO/README.md).

## Como funciona a comunicação por socket

Um socket é a ponta de uma conexão de rede. Dois programas, cada um com seu socket, trocam dados por ele, mesmo estando em computadores diferentes. Cada ponta é identificada por um endereço IP e uma porta:

- O **IP** indica o computador. `localhost` e `127.0.0.1` são o próprio computador.
- A **porta** indica o programa dentro do computador. Aqui, 9000.

O protocolo usado é o TCP (`socket.SOCK_STREAM`): ele estabelece uma conexão antes de trocar dados e garante que os bytes chegam completos e na ordem em que foram enviados.

### O lado do servidor

O servidor é quem espera. Ele passa por quatro etapas:

```python
tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # cria o socket TCP/IPv4
tcp.bind(("localhost", 9000))     # associa o socket ao IP e à porta
tcp.listen(1)                     # passa a aceitar pedidos de conexão
con, client = tcp.accept()        # espera um cliente; devolve um socket novo para ele
```

O `accept()` bloqueia o programa até um cliente se conectar. O socket `con` que ele devolve é o usado para conversar com aquele cliente; o socket original continua só recebendo novos pedidos. Depois disso, `con.recv(1024)` espera e lê até 1024 bytes, e `con.send(...)` envia a resposta.

Este servidor atende **um cliente por vez**: enquanto conversa com um, os outros esperam na fila.

## Como funciona o `try` / `except`

Quando uma operação falha, o Python lança uma **exceção** e, se ninguém a tratar, encerra o programa com uma mensagem de erro. O `try` / `except` captura a exceção e permite continuar:

```python
try:
    resp = eval(msg_s)                 # pode falhar se a expressão for inválida
    con.send(bytes(str(resp), 'ascii'))
except OSError as e:                   # erros de rede: conexão perdida, porta em uso...
    print("Erro de conexão", e.args)
except Exception as e:                 # qualquer outro erro
    con.send(bytes("Erro", 'ascii'))
```

- O bloco `try` é executado normalmente. Se uma linha lançar exceção, o restante do bloco é pulado e o Python procura um `except` compatível.
- Os `except` são testados de cima para baixo, e só o primeiro compatível roda. Por isso o mais específico (`OSError`) vem antes do mais genérico (`Exception`).
- `as e` guarda a exceção numa variável; `e.args` contém a mensagem de erro.

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 3/Servidor`:

```bat
python main.py
```

O servidor fica rodando até a janela ser fechada ou `Ctrl+C` ser pressionado. Com ele no ar, abra **outro** cmd e execute o cliente, como descrito no README de `Python 3/Cliente`.

Exemplo de saída do servidor, com um cliente que enviou `2+3`, `10/4`, `2**10` e `abc`:

```
Servidor iniciado em  localhost :  9000
Atendendo cliente  ('127.0.0.1', 55179)
('127.0.0.1', 55179)  -> requisição atendida
('127.0.0.1', 55179)  -> requisição atendida
('127.0.0.1', 55179)  -> requisição atendida
Erro nos dados recebidos pelo cliente  ('127.0.0.1', 55179) :  ("name 'abc' is not defined",)
```

A porta do cliente (55179) é escolhida pelo sistema e muda a cada conexão.
