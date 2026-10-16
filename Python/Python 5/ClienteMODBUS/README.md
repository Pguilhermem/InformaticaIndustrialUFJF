# Aula 5: Cliente MODBUS

Cliente MODBUS TCP interativo. Ele se conecta ao servidor da pasta [`Python 5/ServidorMODBUS`](../ServidorMODBUS/README.md) e oferece um menu no terminal para ler dados da tabela MODBUS, escrever dados e configurar o tempo de varredura entre leituras.

O cliente usa a biblioteca pymodbus. O protocolo MODBUS, a tabela de dados e os códigos de função estão explicados no README do servidor. A classe `ClienteMODBUS` e o `try` / `except` seguem o que foi explicado em [`Python 2/POO`](../../Python%202/POO/README.md) e no [servidor da Aula 3](../../Python%203/Servidor/README.md).

## Como funciona o cliente MODBUS

O cliente é criado com o IP e a porta do servidor, e a conexão é aberta com `connect()`:

```python
self._cliente = ModbusTcpClient(host=server_ip, port=porta)
self._cliente.connect()
```

Cada tipo de dado da tabela tem um método de leitura ou escrita, que envia o código de função correspondente:

| Menu | Método do pymodbus | Código |
|------|--------------------|--------|
| Ler Holding Register | `read_holding_registers` | 03 |
| Ler Coil | `read_coils` | 01 |
| Ler Input Register | `read_input_registers` | 04 |
| Ler Discrete Input | `read_discrete_inputs` | 02 |
| Escrever Holding Register | `write_register` | 06 |
| Escrever Coil | `write_coil` | 05 |

```python
resp = self._cliente.read_holding_registers(address=addr, count=1, device_id=1)
if resp and not resp.isError():
    return resp.registers[0]
```

- `address` é o endereço na tabela, e `count`, quantas posições seguidas ler.
- `device_id` identifica o equipamento. Ele importa quando vários equipamentos ficam atrás de um mesmo endereço IP, como num conversor para rede serial.
- A resposta pode ser um erro, por exemplo um endereço que não existe no servidor. Por isso o código testa `isError()` antes de usar o valor.
- Registradores ficam em `resp.registers`, e bits (coils e discrete inputs), em `resp.bits`.

### Tempo de varredura

Na opção de leitura, o cliente lê o mesmo endereço várias vezes, esperando o tempo de varredura (`scan_time`, 1 s por padrão) entre uma leitura e outra. É assim que sistemas supervisórios acompanham um equipamento: consultando periodicamente. A opção 3 do menu muda esse tempo.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 5/ClienteMODBUS`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (pymodbus):

```bat
pip install -r requirements.txt
```

A criação do ambiente e a instalação só são necessárias na primeira vez.

## Executar

Primeiro, inicie o servidor num cmd, como descrito no README de `Python 5/ServidorMODBUS`. Depois, com o ambiente ativado neste outro cmd:

```bat
python main.py
```

Para testar com o servidor desta aula:

- Leia o **holding register 1000** (opção 1, tipo 1, endereço 1000): o valor muda a cada leitura, porque o servidor o atualiza a cada segundo.
- Escreva no **holding register 2000** (opção 2, tipo 1) ou no **coil 1000** (opção 2, tipo 2): o novo valor aparece na tabela impressa pelo servidor.

A opção 4 encerra o cliente e fecha a conexão.
