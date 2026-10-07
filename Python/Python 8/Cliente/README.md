# Aula 8: Cliente com Persistência

Cliente MODBUS que guarda as leituras num banco de dados. Ele lê periodicamente quatro holding registers do servidor da pasta [`Python 8/Servidor`](../Servidor/README.md), com temperatura, pressão, umidade e consumo, e grava cada leitura com data e hora num banco SQLite. Ao mesmo tempo, oferece no terminal uma busca pelos dados históricos entre dois horários, exibidos em forma de tabela.

O código está dividido em três arquivos:

- `dbhandler.py`: classe `DBHandler`, que cria a tabela, insere e busca dados no banco.
- `modbuspersistencia.py`: classe `ModbusPersistencia`, que lê o servidor, grava no banco e atende a busca.
- `main.py`: define as tags e seus endereços e inicia o cliente.

O protocolo MODBUS está no README do [servidor da Aula 5](../../Python%205/ServidorMODBUS/README.md). Threads e `Lock` estão em [`Python 4/Sincronismo`](../../Python%204/Sincronismo/README.md).

## Como funciona a persistência com SQLite

Persistir dados é guardá-los de forma que continuem existindo depois que o programa termina. Aqui, eles vão para um banco de dados SQLite: um banco inteiro guardado num único arquivo, `data\data.db`, sem precisar de um servidor de banco de dados. O módulo `sqlite3` faz parte da biblioteca padrão do Python.

```python
self._con = sqlite3.connect(dbpath, check_same_thread=False)   # abre ou cria o arquivo
self._cursor = self._con.cursor()                              # objeto que executa os comandos
self._cursor.execute(sql_str)                                  # executa um comando SQL
self._con.commit()                                             # confirma a gravação no arquivo
```

Os comandos para o banco são escritos em SQL, a linguagem padrão dos bancos de dados relacionais. Este cliente usa três:

**Criar a tabela**, se ela ainda não existir. As colunas são um identificador, a data e hora da leitura e uma coluna para cada tag:

```sql
CREATE TABLE IF NOT EXISTS modbusData(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    timestamp TEXT NOT NULL,
    temperatura REAL, pressao REAL, umidade REAL, consumo REAL);
```

**Inserir uma leitura**, a cada ciclo de varredura:

```sql
INSERT INTO modbusData (timestamp, temperatura, pressao, umidade, consumo)
VALUES ('2026-10-07 14:30:00.123456', 451, 34464, 27, 63);
```

**Buscar as leituras** entre dois horários:

```sql
SELECT timestamp, temperatura, pressao, umidade, consumo
FROM modbusData
WHERE timestamp BETWEEN '2026-10-07 14:00:00' AND '2026-10-07 15:00:00';
```

Os valores nos exemplos são ilustrativos. As datas são guardadas como texto no formato `AAAA-MM-DD HH:MM:SS`, em que a ordem alfabética coincide com a ordem cronológica. É isso que permite comparar horários com `BETWEEN`.

### Duas threads e um banco

O `run()` inicia duas threads: `guardar_dados`, que lê o servidor e grava no banco a cada segundo, e `acesso_dados_historicos`, que espera o usuário digitar os horários da busca. As duas usam a mesma conexão com o banco:

- `check_same_thread=False` permite que a conexão aberta numa thread seja usada por outra. Sem isso, o `sqlite3` recusa o acesso.
- O `Lock` impede que as duas threads executem comandos no banco ao mesmo tempo. Aqui ele é usado com `acquire()` e `release()`, que equivalem ao `with` explicado em `Sincronismo`.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 8/Cliente`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (pyModbusTCP e tabulate):

```bat
pip install -r requirements.txt
```

Crie a pasta onde o banco será gravado:

```bat
mkdir data
```

A pasta `data` não vem com o repositório, porque o `.gitignore` ignora arquivos `.db` e o git não guarda pastas vazias. O SQLite cria o arquivo `data.db`, mas não cria a pasta: sem ela, o cliente encerra com `unable to open database file`.

A criação do ambiente, a instalação e a pasta `data` só são necessárias na primeira vez.

## Executar

Primeiro, inicie o servidor num cmd, como descrito no README de `Python 8/Servidor`. Depois, com o ambiente ativado neste outro cmd:

```bat
python main.py
```

O cliente imprime `Persistência iniciada` e começa a gravar uma leitura por segundo. Para consultar o histórico, digite o horário inicial e o final no formato `DD/MM/AAAA HH:MM:SS`, por exemplo `07/10/2026 14:00:00`. O resultado aparece em forma de tabela, com uma linha por leitura gravada no intervalo.

O cliente fica rodando até a janela ser fechada. Os dados continuam no arquivo `data\data.db` e aparecem nas buscas das próximas execuções.
