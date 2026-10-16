# Aula 9: Cliente com ORM

Versão do [cliente com persistência da Aula 8](../../Python%208/Cliente/README.md) que acessa o banco de dados por meio de um ORM, o SQLAlchemy, em vez de comandos SQL escritos à mão. O funcionamento é o mesmo: o cliente lê temperatura, pressão, umidade e consumo do servidor MODBUS a cada segundo, grava cada leitura num banco SQLite e oferece no terminal uma busca pelos dados históricos entre dois horários.

O código está dividido em quatro arquivos:

- `db.py`: configura a conexão com o banco (engine, base dos modelos e fábrica de sessões).
- `models.py`: classe `DadoCLP`, que descreve a tabela das leituras.
- `modbuspersistencia.py`: classe `ModbusPersistencia`, que lê o servidor, grava no banco e atende a busca.
- `main.py`: define as tags e seus endereços e inicia o cliente.

O SQLite, as duas threads e o `Lock` estão explicados no README do cliente da Aula 8. O protocolo MODBUS está no README do [servidor da Aula 5](../../Python%205/ServidorMODBUS/README.md).

## Como funciona o ORM

Um ORM (Object-Relational Mapping, ou mapeamento objeto-relacional) liga as classes do Python às tabelas do banco. Cada classe de modelo corresponde a uma tabela, cada atributo a uma coluna e cada objeto a uma linha. O ORM gera o SQL sozinho.

### Modelo

```python
class DadoCLP(Base):
    __tablename__ = 'dadoclp'
    id = Column(Integer, primary_key=True)
    timestamp = Column(DateTime)
    temperatura = Column(Integer)
    ...
```

- A classe herda de `Base`, criada em `db.py` com `declarative_base()`. É assim que o SQLAlchemy reconhece a classe como modelo.
- `__tablename__` é o nome da tabela no banco.
- Cada `Column` vira uma coluna, com o tipo indicado: `Integer`, `DateTime`. A data é guardada como `DateTime`, e não como texto, como na Aula 8.

`Base.metadata.create_all(engine)` cria no banco as tabelas de todos os modelos, se ainda não existirem. Ele substitui o `CREATE TABLE IF NOT EXISTS` da Aula 8.

### Engine e sessão

```python
engine = create_engine('sqlite:///data\db.data?check_same_thread=False')
Session = sessionmaker(bind=engine)
```

- O **engine** cuida da conexão com o banco. O texto de conexão indica o tipo de banco (`sqlite`) e o arquivo (`data\db.data`). Trocar esse texto é o suficiente para usar outro banco, como PostgreSQL ou MySQL, sem mudar o resto do código.
- A **sessão** acompanha os objetos criados e alterados e os envia ao banco no `commit()`.

### Inserir e buscar

Inserir uma leitura é criar um objeto do modelo e adicioná-lo à sessão:

```python
dado = DadoCLP(timestamp=datetime.now(), temperatura=451, pressao=34464, umidade=27, consumo=63)
self._session.add(dado)
self._session.commit()
```

Buscar é montar a consulta com métodos, em vez de escrever o `SELECT`:

```python
results = self._session.query(DadoCLP).filter(DadoCLP.timestamp.between(init, final)).all()
```

O resultado é uma lista de objetos `DadoCLP`, um por linha encontrada. O método `get_attr_printable_list` de cada objeto devolve os valores numa lista, com a data formatada, para o `tabulate` exibir.

| Aula 8 (SQL) | Aula 9 (ORM) |
|--------------|--------------|
| `CREATE TABLE IF NOT EXISTS ...` | `Base.metadata.create_all(engine)` |
| `INSERT INTO ... VALUES ...` | `session.add(objeto)` + `session.commit()` |
| `SELECT ... WHERE timestamp BETWEEN ...` | `session.query(Modelo).filter(Modelo.timestamp.between(...))` |

## Preparar o ambiente

Com o cmd aberto na pasta `Python 9/ClienteORM`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (pyModbusTCP, tabulate e SQLAlchemy):

```bat
pip install -r requirements.txt
```

Crie a pasta onde o banco será gravado:

```bat
mkdir data
```

Assim como na Aula 8, a pasta `data` não vem com o repositório, e o SQLite não a cria sozinho.

A criação do ambiente, a instalação e a pasta `data` só são necessárias na primeira vez.

## Executar

Esta aula não tem servidor próprio: ela usa o [servidor da Aula 8](../../Python%208/Servidor/README.md). Inicie-o num cmd e, com o ambiente ativado neste outro cmd:

```bat
python main.py
```

O uso é o mesmo da Aula 8: o cliente imprime `Persistência iniciada`, grava uma leitura por segundo e pede o horário inicial e o final da busca no formato `DD/MM/AAAA HH:MM:SS`. O resultado aparece em forma de tabela, com as colunas `id`, `timestamp`, `temperatura`, `pressao`, `umidade` e `consumo`.
