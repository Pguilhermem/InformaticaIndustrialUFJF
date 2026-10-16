# Aula 3: Exemplo de Processamento de Imagem

Detecta rostos numa foto com a biblioteca OpenCV. O programa lê a imagem `faces/image_0001.jpg`, codifica e decodifica a imagem em bytes, como seria feito para enviá-la por socket, converte para tons de cinza, procura rostos com um classificador pré-treinado e desenha um retângulo verde em volta de cada rosto encontrado. O resultado é exibido numa janela.

## Como funciona o processamento com OpenCV

O OpenCV (`cv2`) representa uma imagem como um array do NumPy com três dimensões: altura, largura e as três cores de cada pixel. A ordem das cores no OpenCV é **BGR** (azul, verde, vermelho), e não RGB.

```python
img = cv2.imread('faces/image_0001.jpg')        # lê o arquivo para um array
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)    # converte para tons de cinza
```

A detecção usa um classificador Haar: um modelo já treinado para reconhecer rostos de frente, que vem junto com o OpenCV no arquivo `haarcascade_frontalface_default.xml`. Ele trabalha em tons de cinza:

```python
face_cascade = cv2.CascadeClassifier(xml_classificador)
faces = face_cascade.detectMultiScale(gray, 1.3, 5)
```

- `1.3` é o fator de escala: o classificador procura rostos em vários tamanhos, reduzindo a imagem 30% a cada passo.
- `5` é o número mínimo de detecções vizinhas para confirmar um rosto. Valores maiores dão menos falsos positivos, mas podem perder rostos.

O resultado é uma lista de retângulos `(x, y, w, h)`: posição do canto superior esquerdo, largura e altura. Cada um é desenhado com `cv2.rectangle`, na cor `(0, 255, 0)`, que em BGR é verde, com 2 pixels de espessura.

```python
cv2.imshow('Imagem Processada', img)   # abre a janela
cv2.waitKey(0)                         # espera uma tecla
cv2.destroyAllWindows()                # fecha a janela
```

## Como funciona a codificação da imagem

Para enviar uma imagem por socket, ela precisa virar uma sequência de bytes (veja `bytes` em [`Python 3/Cliente`](../Cliente/README.md)). O código simula esse envio e a recepção, sem rede:

```python
_, img_bytes = cv2.imencode('.jpg', img)    # array -> arquivo JPEG em memória
img_bytes = bytes(img_bytes)
tamanho_da_imagem_codificado = len(img_bytes).to_bytes(4, 'big')
```

O `recv` do socket lê no máximo a quantidade de bytes pedida, e uma imagem tem milhares de bytes. Por isso, quem envia manda antes o **tamanho** da imagem num campo fixo de 4 bytes. Quem recebe lê esses 4 bytes, descobre quantos bytes ainda faltam e continua lendo até completar a imagem.

- `to_bytes(4, 'big')` converte o número inteiro em 4 bytes. `'big'` (big-endian) indica que o byte mais significativo vem primeiro. Os dois lados precisam usar a mesma ordem.
- `int.from_bytes(..., 'big')` faz a conversão contrária, no lado de quem recebe.
- `cv2.imdecode` transforma os bytes do JPEG de volta num array de imagem.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 3/ExemploProcessamentoImagem`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (OpenCV, que instala também o NumPy):

```bat
pip install -r requirements.txt
```

A criação do ambiente e a instalação só são necessárias na primeira vez.

## Executar

Com o ambiente ativado, e o cmd aberto nesta pasta, porque o caminho da imagem é relativo a ela:

```bat
python main.py
```

O programa abre a janela "Imagem Processada" com a foto e um retângulo verde em volta de cada rosto detectado. Pressione qualquer tecla com a janela selecionada para fechá-la e encerrar o programa.

Para testar outra foto, troque `image_0001.jpg` em `caminho_imagem` por outra imagem da pasta `faces`.

No Python 3.12 ou mais recente, aparece um aviso `SyntaxWarning: invalid escape sequence '\h'` antes da janela. Ele vem da barra invertida no caminho do classificador e não impede o funcionamento.
