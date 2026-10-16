# Aula 2: Programação Orientada a Objetos

Modela contas bancárias com classes. O arquivo `contas.py` define a classe `Conta`, com número, titular, senha e saldo, e os métodos de depósito, saque e exibição de dados, que pedem a senha. A classe `ContaPoupanca` herda tudo de `Conta` e acrescenta uma taxa de rendimento e um método que simula o saldo após alguns meses. O `main.py` cria uma conta de cada tipo e chama esses métodos.

## Como funcionam classes e objetos

Uma classe é o molde, e um objeto é cada exemplar criado a partir dela. A classe define os dados que cada objeto guarda (atributos) e as funções que operam sobre eles (métodos):

```python
class Conta():
    def __init__(self, numero, titular, senha, saldoi=0.0):
        self.numero = numero
        self.titular = titular
        self.__senha = senha
        self._saldo = saldoi

    def deposito(self, valor):
        if valor > 0:
            self._saldo += valor
```

```python
c1 = Conta(1, "João", 1234, 500)   # cria um objeto: chama o __init__
c1.deposito(300)                   # chama um método do objeto
```

- `__init__` é o construtor: roda automaticamente quando o objeto é criado e inicializa os atributos.
- `self` é o próprio objeto. Todo método o recebe como primeiro parâmetro, mas ele não é passado na chamada: em `c1.deposito(300)`, o Python passa `c1` como `self` e `300` como `valor`.
- `self.numero = numero` cria um atributo no objeto. Cada objeto tem os seus: `c1.numero` e `cp.numero` são independentes.

### Encapsulamento

O Python não tem atributos privados como C++ ou Java. O acesso é indicado por convenção no nome:

| Nome | Significado |
|------|-------------|
| `numero` | Público: pode ser lido e alterado de fora da classe. |
| `_saldo` | Um sublinhado: uso interno. O Python não impede o acesso, mas o nome avisa que ele não deve ser feito. |
| `__senha` | Dois sublinhados: o Python renomeia o atributo para `_Conta__senha`, e `c1.__senha` dá `AttributeError` fora da classe. |

O acesso ao saldo é feito pelos métodos `getSaldo`, `saque` e `exibeDados`, que conferem a senha antes.

### Herança

Uma classe derivada herda todos os atributos e métodos da classe base, indicada entre parênteses:

```python
class ContaPoupanca(Conta):
    def __init__(self, numero, titular, senha, taxa=0.002, saldoi=0.0):
        super().__init__(numero, titular, senha, saldoi)
        self.__taxa = taxa
```

O `super()` dá acesso à classe base. Aqui, ele chama o construtor de `Conta` para inicializar número, titular, senha e saldo, e o construtor de `ContaPoupanca` só acrescenta a taxa. Um objeto `ContaPoupanca` pode usar `deposito`, `saque` e `exibeDados` sem que esses métodos sejam reescritos.

## Como funcionam os parâmetros padrão

Um parâmetro com `=` na definição tem um valor padrão, usado quando o argumento não é passado na chamada:

```python
def __init__(self, numero, titular, senha, taxa=0.002, saldoi=0.0):
```

```python
ContaPoupanca(2, "Maria", 1234)               # taxa = 0.002, saldoi = 0.0
ContaPoupanca(2, "Maria", 1234, 0.005, 1200)  # taxa = 0.005, saldoi = 1200
```

Parâmetros com valor padrão vêm depois dos que não têm.

## Como funcionam os argumentos nomeados

Na chamada, um argumento pode ser passado pelo nome do parâmetro. Assim, a ordem deixa de importar e é possível pular parâmetros com valor padrão:

```python
c1 = Conta(1, senha=1234, titular="João", saldoi=500)
cp = ContaPoupanca(2, "Maria", 1234, saldoi=1200)   # pula a taxa, que fica 0.002
```

Os argumentos por posição vêm primeiro, e os nomeados depois.

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 2/POO`:

```bat
python main.py
```

Saída esperada:

```
Saque no valor de R$ 200 realizado com sucesso
Número:  1
Titular:  João
Saldo: R$  600
Número:  2
Titular:  Maria
Saldo: R$  1200
Saldo após 12 meses : R$ 1229.12
```
