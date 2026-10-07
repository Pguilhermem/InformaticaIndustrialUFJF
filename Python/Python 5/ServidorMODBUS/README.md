# Aula 5: Servidor MODBUS

Servidor MODBUS TCP que simula um equipamento industrial. A cada segundo, ele grava no holding register 1000 um valor aleatório entre 380 e 419, como se fosse a leitura de um sensor de tensão em torno de 400, e imprime parte da sua tabela de dados. O cliente que lê e escreve nessa tabela está na pasta [`Python 5/ClienteMODBUS`](../ClienteMODBUS/README.md).

O servidor usa a biblioteca pyModbusTCP. A classe `ServidorMODBUS` e o `try` / `except` seguem o que foi explicado em [`Python 2/POO`](../../Python%202/POO/README.md) e no [servidor da Aula 3](../../Python%203/Servidor/README.md).

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
self._db = DataBank()
self._server = ModbusServer(host=host_ip, port=port, no_block=True, data_bank=self._db)
```

- `DataBank` é a tabela de dados do servidor.
- `no_block=True` faz o `start()` retornar logo, deixando o servidor atender os clientes em segundo plano. Assim, o laço do `run()` pode continuar alterando e imprimindo a tabela.

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

Instale as bibliotecas listadas em `requirements.txt` (pyModbusTCP):

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
