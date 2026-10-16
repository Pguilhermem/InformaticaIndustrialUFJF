# Aula 1: Exemplo de Soma

Lê dois números inteiros digitados no terminal e imprime a soma deles.

## Como funcionam o `input()` e o `int()`

O `input()` espera o usuário digitar algo e pressionar Enter, e devolve o que foi digitado como **texto** (`str`), mesmo que sejam algarismos. O `int()` converte esse texto para número inteiro:

```python
a = int(input())
```

Sem a conversão, o `+` juntaria os textos em vez de somar:

```python
"2" + "3"            # "23"
int("2") + int("3")  # 5
```

Se o texto digitado não for um número inteiro, como `abc` ou `2.5`, o `int()` encerra o programa com `ValueError`.

## Como funciona a f-string

Uma f-string é um texto com a letra `f` antes das aspas. Dentro dela, qualquer expressão entre chaves é calculada e o resultado entra no texto:

```python
print(f'Resultado da soma: {a+b}')   # com a = 2 e b = 3: Resultado da soma: 5
```

Sem o `f`, as chaves são impressas como texto comum: `Resultado da soma: {a+b}`.

## Como funciona o `print(..., end='')`

Por padrão, o `print` termina com uma quebra de linha. O parâmetro `end` troca essa quebra pelo texto indicado. Com `end=''`, nada é acrescentado e o cursor fica na mesma linha:

```python
print("Digite o primeiro operando:", end='')
a = int(input())   # o número é digitado logo depois dos dois-pontos
```

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 1/ExemploSoma`:

```bat
python main.py
```

Exemplo de uso:

```
Digite o primeiro operando:2
Digite o segundo operando:3
Resultado da soma: 5
```
