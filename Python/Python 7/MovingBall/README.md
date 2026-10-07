# Aula 7: Moving Ball

Animação de uma bola azul que se move pela janela e quica nas bordas. Na parte de baixo há um botão "Mover", que inicia e para o movimento, e um controle deslizante que ajusta a velocidade de 1 a 30.

A linguagem `.kv`, `id`, `root` e eventos estão nos READMEs de [`Python 6/BasicApp`](../../Python%206/BasicApp/README.md) e [`Python 6/KivyBasico`](../../Python%206/KivyBasico/README.md). `size_hint` e `Window.size` estão em [`Python 7/BasicApp`](../BasicApp/README.md).

## Como funciona a animação com `Clock`

Uma animação é uma sequência de pequenas mudanças feitas muitas vezes por segundo. O `Clock` do Kivy chama uma função periodicamente:

```python
self._ev = Clock.schedule_interval(self.move, 1.0/60.0)   # chama move 60 vezes por segundo
self._ev.cancel()                                         # para as chamadas
```

O `schedule_interval` devolve um objeto de evento, guardado em `self._ev` para que o botão "Parar" consiga cancelá-lo depois. A função agendada recebe `dt`, o tempo em segundos desde a última chamada.

A cada chamada, `move` soma a velocidade à posição da bola. Quando a bola passa de uma borda, o sinal da velocidade naquele eixo é invertido, e ela volta:

```python
self.ids.bola.x += self._vel[0]
if self.ids.bola.x < 0 or self.ids.bola.right > self.ids.valid_region.width:
    self._vel[0] *= -1
```

`x` e `y` são a posição do canto inferior esquerdo do widget, e `right` e `top`, as bordas direita e superior. No Kivy, o eixo `y` cresce de baixo para cima.

O botão alterna entre "Mover" e "Parar": o método `command` decide o que fazer pelo texto atual do botão.

## Como funciona o desenho com `canvas`

Widgets comuns, como `Button` e `Label`, já sabem se desenhar. Um `Widget` simples é invisível: o que ele mostra é definido no seu `canvas`, com instruções de desenho executadas em ordem:

```
Widget:
    id: bola
    size_hint: None, None
    size: 50, 50
    canvas:
        Color:
            rgba: 0, 0, 1, 1
        Ellipse:
            pos: self.pos
            size: self.size
```

- `Color` define a cor das instruções seguintes, aqui azul.
- `Ellipse` desenha uma elipse. Com largura e altura iguais, é um círculo.
- `pos: self.pos` liga a posição do desenho à do widget. Quando `move` altera `bola.x`, o círculo acompanha.
- `size_hint: None, None` desliga o tamanho proporcional, para o `size: 50, 50` valer em pixels.

## Como funcionam o `RelativeLayout` e o `Slider`

A bola fica dentro de um `RelativeLayout` (`valid_region`), que ocupa a parte de cima da janela. Num `RelativeLayout`, as posições dos filhos são contadas a partir do canto do próprio layout, e não da janela. Por isso `move` compara a bola com 0 e com `valid_region.width` e `valid_region.height`.

O `Slider` é um controle deslizante com valor entre `min` e `max`. Ao arrastá-lo, o evento `on_touch_move` atualiza `_vel` com o novo valor, mantendo o sentido em que a bola estava se movendo.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 7/MovingBall`, crie o ambiente `.venv`:

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

O Kivy imprime algumas linhas de registro (`[INFO ...]`) no cmd e abre a janela do aplicativo. Clique em "Mover" para iniciar a animação e arraste o controle "Velocidade" para mudar a rapidez da bola. O programa termina quando a janela é fechada.
