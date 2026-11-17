# Aula 5: Servidor MODBUS

Servidor MODBUS TCP que simula um equipamento industrial. A cada segundo, ele grava no holding register 1000 um valor aleatório entre 380 e 419, como se fosse a leitura de um sensor de tensão em torno de 400, e imprime parte da sua tabela de dados. O cliente que lê e escreve nessa tabela está na pasta [`Python 5/ClienteMODBUS`](../ClienteMODBUS/README.md).

O servidor usa a biblioteca pymodbus, versão 3.7.2. A classe `ServidorMODBUS` e o `try` / `except` seguem o que foi explicado em [`Python 2/POO`](../../Python%202/POO/README.md) e no [servidor da Aula 3](../../Python%203/Servidor/README.md).

## Como funciona o MODBUS

MODBUS é um protocolo de comunicação usado em automação industrial para ler e escrever dados em equipamentos como CLPs, inversores e medidores. A comunicação segue o modelo cliente/servidor: o **cliente** (antes chamado de mestre) faz as requisições, e o **servidor** (antes chamado de escravo) guarda os dados e responde. A versão MODBUS TCP usa a rede Ethernet, e a porta padrão é a 502.

### Tabela de dados

O servidor organiza seus dados em quatro tabelas. Cada posição é identificada por um endereço numérico:

| Tipo | Conteúdo | Acesso pelo cliente | Uso típico |
|------|----------|---------------------|------------|
| Coil | 1 bit | Leitura e escrita | Saídas digitais: ligar um motor |
| Discrete Input | 1 bit | Só leitura | Entradas digitais: estado de um sensor fim de curso |
| Input Register | 16 bits | Só leitura | Medições: valor de um sensor analógico |
| Holding Register | 16 bits | Leitura e escrita | Parâmetros e valores de processo |

### Códigos de função

Cada requisição do cliente leva um código que indica a operação. Os usados nestas aulas:

| Código | Operação |
|--------|----------|
| 01 | Ler coils |
| 02 | Ler discrete inputs |
| 03 | Ler holding registers |
| 04 | Ler input registers |
| 05 | Escrever um coil |
| 06 | Escrever um holding register |

### O que este servidor faz

```python
self._db = ModbusSlaveContext(
    co=ModbusSequentialDataBlock(1000, [False] * 1000),
    di=ModbusSequentialDataBlock(0, [False] * 1000),
    ir=ModbusSequentialDataBlock(0, [0] * 1000),
    hr=ModbusSparseDataBlock({1000:0,2000:[0]*1000}),
    zero_mode=True,
)
contexto = ModbusServerContext(slaves=self._db, single=True)

self._server = Thread(
    target=StartTcpServer,
    kwargs={"context": contexto, "address": (host_ip, port)},
    daemon=True,
)
```

- `ModbusSlaveContext` é a tabela de dados do servidor, com um bloco para cada tipo: `co` (coils), `di` (discrete inputs), `ir` (input registers) e `hr` (holding registers).
- `ModbusSequentialDataBlock(inicio, valores)` cria posições seguidas a partir do endereço `inicio`, uma para cada item da lista. Os coils vão de 1000 a 1999; discrete inputs e input registers, de 0 a 999.
- `ModbusSparseDataBlock` recebe um dicionário só com os endereços que existem. Uma lista vira posições seguidas, então os holding registers são o 1000 e os de 2000 a 2999.
- Um endereço fora dos blocos responde com erro `IllegalAddress`.
- `zero_mode=True` faz o endereço pedido pelo cliente ser o mesmo da tabela. Sem ele, o pymodbus soma 1 ao endereço.
- `ModbusServerContext` junta as tabelas do servidor. Com `single=True`, a mesma tabela responde a qualquer `device_id` enviado pelo cliente.
- `StartTcpServer` põe o servidor no ar e não retorna enquanto ele estiver rodando. Por isso ele é executado numa thread (ver [`Python 4/Sincronismo`](../../Python%204/Sincronismo/README.md)): o `start()` retorna logo, e o laço do `run()` pode continuar alterando e imprimindo a tabela. Com `daemon=True`, a thread termina junto com o programa.

A tabela é lida e alterada com `getValues` e `setValues`. O primeiro argumento é o código de função que indica o tipo de dado: 1 para coils, 2 para discrete inputs, 3 para holding registers e 4 para input registers.

```python
self._db.setValues(3, 1000, [valor])   # grava no holding register 1000
self._db.getValues(1, 1000)            # lê o coil 1000
```

A cada segundo, o laço grava o valor aleatório no holding register 1000 e imprime os holding registers 1000 e 2000 e o coil 1000. Os endereços 2000 e 1000 (coil) não são alterados pelo servidor: eles mostram o que o cliente escrever neles.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 5/ServidorMODBUS`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (pymodbus 3.7.2):

```bat
pip install -r requirements.txt
```

A criação do ambiente e a instalação só são necessárias na primeira vez.

## Executar

Com o ambiente ativado:

```bat
python main.py
```

O servidor imprime `Servidor MODBUS em execução` e, a cada segundo, o conteúdo dos endereços monitorados. Ele fica rodando até a janela ser fechada ou `Ctrl+C` ser pressionado. Com ele no ar, abra **outro** cmd e execute o cliente, como descrito no README de `Python 5/ClienteMODBUS`.
