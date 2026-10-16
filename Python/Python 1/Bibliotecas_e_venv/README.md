# Aula 1: Bibliotecas e Ambiente Virtual

Gera e exibe o gráfico de uma tensão senoidal de 60 Hz e 220 V eficazes, ao longo de dois períodos. O código usa duas bibliotecas externas: o NumPy, para criar o vetor de tempo e calcular a senoide, e o Matplotlib, para desenhar o gráfico. Como essas bibliotecas não vêm com o Python, elas são instaladas num ambiente virtual.

## Como funciona o ambiente virtual

Um ambiente virtual (venv) é uma pasta com uma cópia isolada do Python, onde as bibliotecas de um projeto são instaladas sem afetar o Python do sistema nem outros projetos. Cada projeto pode ter suas próprias bibliotecas, em versões diferentes, sem conflito.

O fluxo tem três passos:

1. Criar o ambiente, uma vez por projeto. O comando cria uma pasta com o nome escolhido:

   ```bat
   python -m venv <nome_do_ambiente>
   ```

2. Ativar o ambiente, sempre que abrir um terminal novo. Depois de ativado, o nome do ambiente aparece entre parênteses no início da linha do cmd, e os comandos `python` e `pip` passam a usar o ambiente:

   ```bat
   <nome_do_ambiente>\Scripts\activate
   ```

3. Instalar as bibliotecas com o `pip`, o gerenciador de pacotes do Python. Elas ficam dentro da pasta do ambiente e só existem para este projeto.

   Uma biblioteca:

   ```bat
   pip install <nome_da_biblioteca>
   ```

   Várias de uma vez, separadas por espaço:

   ```bat
   pip install <biblioteca_1> <biblioteca_2>
   ```

   A partir de um arquivo. Por convenção, os projetos Python listam suas bibliotecas num arquivo chamado `requirements.txt`, uma por linha:

   ```bat
   pip install -r requirements.txt
   ```

Para sair do ambiente, use `deactivate`.

## Como funciona o `import ... as`

O `import` carrega uma biblioteca para dentro do programa. Com `as`, a biblioteca ganha um apelido mais curto:

```python
import numpy as np
import matplotlib.pyplot as plt

y = np.sin(x)    # sem o apelido seria numpy.sin(x)
plt.show()       # sem o apelido seria matplotlib.pyplot.show()
```

`np` e `plt` são os apelidos usados pela própria documentação dessas bibliotecas, por isso aparecem em quase todo código que as utiliza.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 1/Bibliotecas_e_venv`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (NumPy e Matplotlib):

```bat
pip install -r requirements.txt
```

A criação do ambiente e a instalação só são necessárias na primeira vez. O VS Code costuma detectar o ambiente criado e perguntar se deve usá-lo: basta responder que sim.

## Executar

Com o ambiente ativado:

```bat
python main.py
```

O programa abre uma janela com o gráfico "Demonstração Matplotlib": dois ciclos de uma senoide com pico de cerca de 311 V (220 × √2) em 1/30 s. O programa termina quando a janela é fechada.
