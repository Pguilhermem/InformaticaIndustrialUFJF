# Aula 7: Basic App

Aplicativo Kivy com um único botão vermelho "Incrementar", centralizado numa janela de 800 × 600 pixels. O botão ocupa 20% da largura e da altura da janela e continua centralizado quando ela é redimensionada. Ele não tem ação associada: o exemplo mostra só o posicionamento.

A linguagem `.kv`, o carregamento automático de `basic.kv` e o funcionamento de `App` e `build` estão nos READMEs de [`Python 6/BasicApp`](../../Python%206/BasicApp/README.md) e [`Python 6/KivyBasico`](../../Python%206/KivyBasico/README.md).

## Como funciona o `FloatLayout`

O `BoxLayout`, usado na Aula 6, divide o espaço em partes iguais. O `FloatLayout` deixa cada widget escolher seu tamanho e sua posição, em proporção ao tamanho do layout:

```
<MyWidget>:
    Button:
        size_hint: (0.2, 0.2)
        pos_hint: {'center_x': 0.5, 'center_y': 0.5}
```

- `size_hint: (0.2, 0.2)` faz o botão ocupar 20% da largura e 20% da altura do layout.
- `pos_hint` posiciona o botão por proporção. `'center_x': 0.5` põe o centro do botão na metade da largura. Também existem `'x'`, `'right'`, `'y'` e `'top'` para alinhar pelas bordas.

Como os valores são proporções, o botão mantém tamanho e posição relativos quando a janela muda de tamanho.

## Como funciona o tamanho da janela

O objeto `Window` representa a janela do aplicativo. As propriedades são definidas antes do `run()`:

```python
Window.size = (800, 600)      # largura e altura em pixels
Window.fullscreen = False     # janela comum, não tela cheia
```

## Preparar o ambiente

Com o cmd aberto na pasta `Python 7/BasicApp`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (Kivy):

```bat
pip install -r requirements.txt
```

A criação do ambiente e a instalação só são necessárias na primeira vez.

## Executar

Com o ambiente ativado:

```bat
python main.py
```

O Kivy imprime algumas linhas de registro (`[INFO ...]`) no cmd e abre a janela do aplicativo. O programa termina quando a janela é fechada.
