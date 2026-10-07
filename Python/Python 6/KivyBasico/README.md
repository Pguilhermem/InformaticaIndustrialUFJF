# Aula 6: Kivy Básico

Primeiro aplicativo com interface gráfica, usando a biblioteca Kivy. A janela tem um rótulo, um botão e, à direita, dois rótulos empilhados, o de cima em vermelho. Todos começam em 0. Cada clique no botão soma 1 ao primeiro rótulo, 2 ao vermelho e 3 ao último. Toda a interface é montada em código Python. A pasta [`BasicApp`](../BasicApp/README.md), desta mesma aula, monta uma interface parecida com a linguagem `.kv`.

A classe `BasicApp` herda de `App`, como explicado em [`Python 2/POO`](../../Python%202/POO/README.md).

## Como funciona um aplicativo Kivy

Um aplicativo Kivy é uma classe que herda de `App`. O método `build` monta a interface e devolve o widget principal, que ocupa a janela toda. O `run()` abre a janela e mantém o aplicativo rodando até ela ser fechada:

```python
class BasicApp(App):
    def build(self):
        layout = BoxLayout(orientation='horizontal')
        ...
        return layout

BasicApp().run()
```

### Widgets e layouts

Tudo o que aparece na tela é um **widget**: `Label` mostra um texto, e `Button` é um botão. Um **layout** é um widget que organiza outros dentro dele. O `BoxLayout` divide o espaço em partes iguais, lado a lado (`'horizontal'`) ou um embaixo do outro (`'vertical'`):

```python
layout = BoxLayout(orientation='horizontal')
layout.add_widget(self.lb)       # primeira parte, à esquerda
layout.add_widget(bt)            # segunda parte

layout2 = BoxLayout(orientation='vertical')
layout2.add_widget(self.lb2)     # em cima
layout2.add_widget(self.lb3)     # embaixo
layout.add_widget(layout2)       # terceira parte: um layout dentro do outro
```

Colocar layouts dentro de layouts é o modo de montar interfaces mais complexas.

### Eventos

Um botão avisa quando é clicado por meio de eventos. Passar uma função em `on_release` faz o Kivy chamá-la quando o botão é solto:

```python
bt = Button(text="Botão 1", on_release=self.incrementar)
```

A função recebe o texto dos rótulos, converte para número, soma e grava de volta como texto: `self.lb.text = str(int(self.lb.text) + 1)`. Os rótulos são guardados em `self` para que `incrementar` consiga acessá-los depois que o `build` termina.

## Como funciona o `*args`

Um parâmetro com `*` recebe qualquer quantidade de argumentos, reunidos numa tupla:

```python
def incrementar(self, *args):
    ...
```

Ao chamar a função do evento, o Kivy passa como argumento o botão que foi clicado. O `incrementar` não usa esse botão, mas precisa aceitá-lo: sem o `*args`, a chamada daria `TypeError` por receber um argumento a mais.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 6/KivyBasico`, crie o ambiente `.venv`:

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
