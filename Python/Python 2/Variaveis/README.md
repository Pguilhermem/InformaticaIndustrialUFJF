# Aula 2: Variáveis

Mostra como as variáveis funcionam em Python: cada variável é um nome que aponta para um objeto na memória. O programa usa a função `id()` para acompanhar para qual objeto cada nome aponta, primeiro com inteiros, que são imutáveis, e depois com uma lista, que é mutável.

## Como funcionam as variáveis

Em Python, uma variável não é uma caixa que guarda um valor. Ela é um **nome** ligado a um **objeto**. A atribuição `b = a` não copia o objeto: faz o nome `b` apontar para o mesmo objeto que `a`.

A função `id()` devolve o identificador do objeto, que é diferente para cada objeto existente ao mesmo tempo. Dois nomes com o mesmo `id` apontam para o mesmo objeto.

### Objetos imutáveis

Inteiros, `float`, textos (`str`) e tuplas são imutáveis: o objeto nunca muda de valor. Toda operação que parece alterá-lo cria um objeto novo e faz o nome apontar para ele:

```python
a = 3
b = a        # a e b apontam para o mesmo objeto 3: mesmo id
b = 4        # b passa a apontar para outro objeto: id muda; a continua 3
a += 3       # cria o objeto 6 e faz a apontar para ele: id muda
```

### Objetos mutáveis

Listas, dicionários e a maioria dos objetos de classes são mutáveis: o próprio objeto pode ser alterado. Se dois nomes apontam para ele, a alteração aparece pelos dois:

```python
a = [1, 2, 3]
b = a          # a e b apontam para a mesma lista
b.append(4)    # altera a lista: a também vale [1, 2, 3, 4]
a.append(5)    # o id continua o mesmo: é a mesma lista
```

Para ter uma cópia independente, é preciso copiar explicitamente: `b = a.copy()` ou `b = list(a)`.

## Executar

O código usa apenas a biblioteca padrão do Python, então não precisa de ambiente virtual. Com o cmd aberto na pasta `Python 2/Variaveis`:

```bat
python main.py
```

Exemplo de saída:

```
Valor:  3
Identificador de a:  140719511955960
Identificador de b antes da mudança:  140719511955960
Identificador de b após a mudança:  140719511955992
Valor:  6
Identificador:  140719511956056
Valor:  [1, 2, 3, 4]
Identificador:  2614170556608
Identificador:  2614170556608
Valor:  [1, 2, 3, 4, 5]
Identificador:  2614170556608
```

Os números de identificação mudam a cada execução. O que importa é quais são iguais entre si: `a` e `b` têm o mesmo `id` antes de `b = 4` e ids diferentes depois; o `id` de `a` muda depois de `a += 3`; e as três linhas finais mostram o mesmo `id` para a lista, mesmo depois dos dois `append`.
