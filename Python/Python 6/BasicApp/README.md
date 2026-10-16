# Aula 6: Basic App

Aplicativo Kivy com a interface descrita na linguagem `.kv`, em vez de montada em Python. A janela tem um botão vermelho "Incrementar", um rótulo que começa em 0 e, à direita, um botão "Limpar" ao lado de um rótulo fixo "Label2". "Incrementar" soma 1 ao rótulo, e "Limpar" o volta para 0.

O funcionamento de `App`, `build`, widgets, `BoxLayout` e eventos está no README de [`Python 6/KivyBasico`](../KivyBasico/README.md).

## Como funciona a linguagem `.kv`

A linguagem `.kv` separa a aparência da interface do código Python. O arquivo `basic.kv` descreve quais widgets existem, como estão organizados e suas propriedades. O `main.py` fica só com a lógica.

### Carregamento automático

O Kivy carrega sozinho o arquivo `.kv` cujo nome é o da classe do aplicativo sem o final `App`, em letras minúsculas. A classe `BasicApp` carrega `basic.kv`. Se o nome do arquivo não seguir essa regra, a janela abre vazia.

### Regras de classe

Uma regra entre `< >` define a aparência de uma classe Python. Tudo o que estiver indentado abaixo dela vira filho do widget:

```
<MyWidget>:
    orientation: 'horizontal'
    Button:
        text: 'Incrementar'
    Label:
        id: lb
        text: '0'
```

A classe `MyWidget`, em `main.py`, herda de `BoxLayout`. Quando o `build` cria um `MyWidget()`, ele já vem com o botão e o rótulo descritos na regra.

### `id`, `root` e eventos

- `id` dá um nome ao widget dentro da regra. Outros widgets da mesma regra o acessam por esse nome: o botão "Limpar" faz `lb.text = '0'`.
- `root` é o widget da regra, aqui o `MyWidget`. Assim o arquivo `.kv` chama métodos da classe Python: `on_press: root.changelb()`.
- Do lado do Python, os widgets com `id` ficam no dicionário `self.ids`: `self.ids.lb` e `self.ids['lb']` são o mesmo rótulo.
- `on_press` executa o código quando o botão é pressionado. Diferente do `on_release` usado em `KivyBasico`, que executa quando o botão é solto.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 6/BasicApp`, crie o ambiente `.venv`:

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
