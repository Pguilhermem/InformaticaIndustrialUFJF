# Aula 4: Servidor Multithread

Versão do servidor calculadora da [Aula 3](../../Python%203/Servidor/README.md) que atende vários clientes ao mesmo tempo. O arquivo `servidor.py` traz a classe `Servidor`, igual à da Aula 3, e a classe `ServidorMT`, que herda dela e muda só o método `start`: cada cliente que se conecta passa a ser atendido numa thread própria.

O funcionamento dos sockets e do `try` / `except` está no README do [servidor da Aula 3](../../Python%203/Servidor/README.md). Herança e `super()` estão em [`Python 2/POO`](../../Python%202/POO/README.md).

## Por que o servidor precisa de threads

O servidor da Aula 3 faz tudo numa única sequência: aceita um cliente e fica preso no laço de atendimento dele até ele sair. Enquanto isso, o `accept()` não é chamado de novo, e um segundo cliente fica esperando sem resposta.

O `ServidorMT` separa as duas tarefas. O laço principal só aceita conexões; o atendimento de cada cliente roda numa thread, que executa em paralelo com o resto do programa:

```python
while True:
    con, client = self.__tcp.accept()
    self.__threadPool[client] = threading.Thread(target=self._service, args=(con, client))
    self.__threadPool[client].start()
```

- `target` é a função que a thread vai executar, aqui o mesmo `_service` da classe `Servidor`.
- `args` é a tupla de argumentos passados para essa função.
- `start()` inicia a thread e retorna na hora, e o laço volta ao `accept()` para esperar o próximo cliente.

As threads ficam guardadas no dicionário `__threadPool`, com o endereço do cliente como chave.

O que é uma thread, e os cuidados quando várias threads usam os mesmos dados, estão explicados em [`Python 4/Sincronismo`](../Sincronismo/README.md).

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 4/ServidorMT`:

```bat
python main.py
```

O servidor fica rodando até a janela ser fechada ou `Ctrl+C` ser pressionado. O cliente é o mesmo da Aula 3: com o servidor no ar, abra **dois ou mais** cmd na pasta [`Python 3/Cliente`](../../Python%203/Cliente/README.md) e execute `python main.py` em cada um. Todos os clientes recebem resposta ao mesmo tempo, sem esperar os outros saírem, e o servidor imprime uma linha `Atendendo cliente` para cada um.
