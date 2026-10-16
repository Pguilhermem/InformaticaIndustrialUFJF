# Aula 2: Módulos

Demonstra como dividir um programa em arquivos. O arquivo `minhalib.py` define as funções `soma` e `divisao` e a lista `lista`, com os quadrados de 0 a 9. O `main.py` importa esses nomes e imprime o resultado de uma soma, de uma divisão e a lista. O `minhalib.py` também pode ser executado sozinho, como uma calculadora que recebe os números e a operação pela linha de comando.

## Como funcionam os módulos

Todo arquivo `.py` é um módulo, e o nome do módulo é o nome do arquivo sem a extensão. Outro arquivo na mesma pasta pode importar o que ele define:

```python
from minhalib import soma, divisao, lista as lst
```

Esse comando lê-se "do módulo `minhalib`, importe `soma`, `divisao` e `lista`, e chame `lista` de `lst`". Depois disso, os nomes são usados diretamente: `soma(1.75, 2)`.

A outra forma é importar o módulo inteiro e acessar cada nome com o prefixo:

```python
import minhalib

minhalib.soma(1.75, 2)
```

O `main.py` traz essa forma comentada na linha 3.

### `if __name__ == "__main__"`

Quando um módulo é importado, todo o código dele é executado. Para que um trecho rode só quando o arquivo é executado diretamente, e não quando é importado, ele fica dentro deste `if`:

```python
if __name__ == "__main__":
    # roda com "python minhalib.py", mas não com "import minhalib"
```

O Python dá à variável `__name__` o valor `"__main__"` no arquivo executado e o nome do módulo (`"minhalib"`) no arquivo importado.

## Como funcionam o `def` e a docstring

O `def` define uma função: nome, parâmetros entre parênteses e, no bloco indentado, o código. O `return` devolve o resultado:

```python
def divisao(dividendo, divisor):
    """
    Função que retorna a divisão do dividendo pelo divisor
    :param dividendo: dividendo da operação
    :param divisor: divisor da operação
    :return: divisão do dividendo pelo divisor
    """
    return dividendo / divisor
```

O texto entre `"""` logo abaixo do `def` é a docstring: a documentação da função. O VS Code a mostra quando o mouse passa sobre o nome da função ou durante a digitação da chamada, inclusive em outro arquivo que a importou. As linhas `:param` e `:return:` seguem o formato reStructuredText, um dos padrões para descrever parâmetros e retorno.

## Como funciona o `sys.argv`

O `sys.argv`, da biblioteca padrão `sys`, é uma lista com os textos digitados na linha de comando. A posição 0 é o nome do arquivo, e as seguintes são os argumentos:

```bat
python minhalib.py 3 4 +
```

```python
sys.argv[0]   # "minhalib.py"
sys.argv[1]   # "3"
sys.argv[2]   # "4"
sys.argv[3]   # "+"
```

Todos os elementos são texto. Por isso o código converte os números com `float()` antes de calcular.

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 2/Modulos`:

```bat
python main.py
```

Saída esperada:

```
3.75
18.181818181818183
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
```

Para usar o `minhalib.py` como calculadora, passe dois números e a operação, `+` ou `/`:

```bat
python minhalib.py 3 4 +
python minhalib.py 10 4 /
```

Saída esperada:

```
7.0
2.5
```

Qualquer outra operação imprime `Operação inválida`. Se faltar algum dos três argumentos, o programa encerra com `IndexError`.
