# Aula 3: Cliente

Cliente TCP da calculadora em rede. Ele se conecta ao servidor da pasta [`Python 3/Servidor`](../Servidor/README.md) na porta 9000, lê expressões matemáticas digitadas no terminal, como `2+3`, envia cada uma ao servidor e imprime o resultado recebido. Digitar `x` encerra o cliente.

O funcionamento dos sockets e do `try` / `except` está explicado no README do servidor. A classe `Cliente`, em `cliente.py`, usa atributos com `__` e docstrings, explicados em [`Python 2/POO`](../../Python%202/POO/README.md).

## O lado do cliente

O cliente é quem toma a iniciativa. Ele cria o socket e se conecta ao IP e à porta do servidor:

```python
tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp.connect(("127.0.0.1", 9000))   # falha se o servidor não estiver no ar
```

Depois de conectado, usa o mesmo socket para enviar (`send`) e receber (`recv`), e o fecha com `close()` ao terminar.

## Como funcionam `bytes` e `decode`

O socket transmite **bytes**, não texto. Antes de enviar, o texto é convertido para bytes; ao receber, os bytes são convertidos de volta para texto. A conversão segue uma codificação, que define qual byte representa cada caractere:

```python
tcp.send(bytes(msg, 'ascii'))     # texto -> bytes
resp = tcp.recv(1024)             # recebe bytes, por exemplo b'5'
print(resp.decode('ascii'))       # bytes -> texto: '5'
```

Os dois lados precisam usar a mesma codificação. Aqui é `'ascii'`, que só cobre letras sem acento, algarismos e símbolos básicos: um texto com `ç` ou `é` não pode ser convertido, e o cliente imprime `Erro ao realizar comunicação com o servidor` e encerra. A forma equivalente e mais comum de converter é `msg.encode('utf-8')`, com o `utf-8`, que aceita qualquer caractere.

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Primeiro, inicie o servidor num cmd, como descrito no README de `Python 3/Servidor`. Depois, com **outro** cmd aberto na pasta `Python 3/Cliente`:

```bat
python main.py
```

Se o servidor não estiver rodando, o cliente imprime `Servidor não disponível` e encerra.

Exemplo de uso:

```
Conexão realizada com sucesso!
Digite a operação (x para sair): 2+3
=  5
Digite a operação (x para sair): 10/4
=  2.5
Digite a operação (x para sair): 2**10
=  1024
Digite a operação (x para sair): abc
=  Erro
Digite a operação (x para sair): x
```

Depois de um `Erro`, o servidor para de atender este cliente sem fechar a conexão. Se outra operação for enviada, o cliente fica esperando uma resposta que não vem e trava; nesse caso, feche a janela do cmd. Para evitar isso, digite `x` logo depois do `Erro` e execute o cliente de novo.
