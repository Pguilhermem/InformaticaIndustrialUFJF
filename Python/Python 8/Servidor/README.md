# Aula 8: Servidor

Servidor MODBUS TCP que simula quatro medições de um processo industrial. A cada segundo, ele grava valores aleatórios em quatro holding registers, que o cliente da pasta [`Python 8/Cliente`](../Cliente/README.md) lê e armazena num banco de dados.

O protocolo MODBUS, a tabela de dados e o funcionamento do servidor com pyModbusTCP estão no README do [servidor da Aula 5](../../Python%205/ServidorMODBUS/README.md).

## Valores simulados

| Holding register | Medição | Faixa gerada |
|------------------|---------|--------------|
| 1000 | Temperatura | 400 a 499 |
| 1001 | Pressão | 100000 a 119999 |
| 1002 | Umidade | 20 a 39 |
| 1003 | Consumo | 40 a 99 |

Os valores são sorteados com `random.randrange(inicio, fim)`, que não inclui o `fim`.

Um holding register tem 16 bits e guarda valores de 0 a 65535. A faixa da pressão passa desse limite, então o valor lido pelo cliente no registrador 1001 não corresponde ao sorteado.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 8/Servidor`, crie o ambiente `.venv`:

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

O servidor imprime `Servidor em execução` e fica rodando até a janela ser fechada ou `Ctrl+C` ser pressionado. Diferente do servidor da Aula 5, ele não imprime a tabela a cada segundo. Com ele no ar, abra **outro** cmd e execute o cliente, como descrito no README de `Python 8/Cliente`.
