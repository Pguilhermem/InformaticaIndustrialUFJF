# Aula 5: Simulador MODBUS

Simulador de um equipamento MODBUS TCP feito com a classe `ModbusSimulatorServer` da biblioteca pymodbus. Diferente do [servidor desta aula](../ServidorMODBUS/README.md), aqui não se escreve a tabela de dados no código: ela é descrita no arquivo `setup.json`, e o `main.py` só carrega esse arquivo e põe o simulador no ar. Além do MODBUS, o simulador abre uma página web em `http://localhost:8080` que mostra os registradores.

O protocolo MODBUS, a tabela de dados e os códigos de função estão explicados no README do [servidor](../ServidorMODBUS/README.md). O cliente que lê e escreve nesta tabela é o da pasta [`Python 5/ClienteMODBUS`](../ClienteMODBUS/README.md).

## Como funciona o simulador

O `main.py` cria o simulador indicando quais configurações do `setup.json` usar e chama `run_forever()`, que só retorna quando o programa é encerrado:

```python
simulador = ModbusSimulatorServer(
    modbus_server="servidor",
    modbus_device="equipamento",
    http_host="localhost",
    http_port=8080,
    json_file=str(ARQUIVO_JSON),
)
await simulador.run_forever()
```

- `modbus_server` é o nome da comunicação dentro de `server_list` no `setup.json`.
- `modbus_device` é o nome do equipamento dentro de `device_list`.
- `http_host` e `http_port` definem onde fica a página web.

O `ModbusSimulatorServer` é escrito com `asyncio`, por isso o `main.py` usa `async def`, `await` e `asyncio.run()`.

### O arquivo setup.json

O arquivo tem duas partes. A `server_list` diz como o simulador se comunica:

```json
"servidor": {
    "comm": "tcp",
    "host": "localhost",
    "port": 502,
    "framer": "socket"
}
```

A `device_list` descreve a tabela de dados do equipamento. O `setup` define o tamanho da tabela e os valores iniciais, e as listas seguintes dizem o que existe em cada endereço:

```json
"write": [ [1,2], [4,7], 10, [25,26] ],
"bits": [10],
"uint16": [1,2,
    {"addr": 3, "action": "random", "parameters": {"minval": 380, "maxval": 419}},
    {"addr": 27, "action": "increment", "parameters": {"minval": 0, "maxval": 100}},
    {"addr": 28, "action": "uptime"},
    {"addr": 29, "action": "timestamp"}, [30,35],
    {"addr": 36, "action": "reset"}
],
"float32": [[4,5],[6,7],
    {"addr": [8,9], "action": "random", "parameters": {"minval": 20.0, "maxval": 30.0}}
],
"string": [{"addr": [11, 26], "value": "Informatica Industrial - ENE???"}],
```

- Um endereço só existe se aparecer numa lista de tipo (`bits`, `uint16`, `uint32`, `float32`, `string`). Qualquer outro responde com erro `IllegalAddress`.
- Um endereço só aceita escrita se estiver em `write`. Cada item é um endereço (`10`) ou uma faixa (`[4,7]` é de 4 a 7).
- `uint16` ocupa um registrador. `float32` e `uint32` ocupam dois, por isso aparecem como pares.
- `bits` guarda 16 bits num registrador, usados como coils e discrete inputs.
- `string` guarda 2 caracteres por registrador. O texto tem 31 caracteres e ocupa 16 registradores (11 a 26); o último é completado com um espaço.
- Uma entrada pode ser um objeto com `addr` e `action`. A ação roda **a cada leitura** do cliente, não de tempos em tempos.

Todas as listas precisam estar no arquivo, mesmo vazias.

Com este `setup.json`, a tabela fica assim:

| Endereço do registrador | Tipo | Conteúdo | Escrita |
|-------------------------|------|----------|---------|
| 1, 2 | `uint16` | Um valor inteiro cada | Sim |
| 3 | `uint16` | Aleatório entre 380 e 419 (`random`) | Não |
| 4 e 5, 6 e 7 | `float32` | Um número real em cada par | Sim |
| 8 e 9 | `float32` | Aleatório entre 20,0 e 30,0 (`random`) | Não |
| 10 | `bits` | Coils e discrete inputs de 160 a 175 | Sim |
| 11 a 24 | `string` | "Informatica Industrial - ENE" | Não |
| 25 e 26 | `string` | "???" do código da disciplina, mais o espaço final | Sim |
| 27 | `uint16` | Contador de 0 a 100 (`increment`) | Não |
| 28 | `uint16` | Segundos desde que o simulador subiu (`uptime`) | Não |
| 29 a 35 | `uint16` | Data e hora (`timestamp`) | Não |
| 36 | `uint16` | Simula uma falha do equipamento (`reset`) | Não |

O 0 e os endereços de 37 em diante não existem.

### Ações

- **`random`** sorteia um valor entre `minval` e `maxval`. Os endereços 3, 8 e 9 ficaram fora de `write`, então são só de leitura, como uma medição.
- **`increment`** soma 1 a cada leitura e volta a `minval` depois de passar de `maxval`. Funciona como um contador de peças ou de ciclos.
- **`uptime`** devolve os segundos desde que o simulador foi iniciado.
- **`timestamp`** fica no endereço 29, mas cada leitura dele grava a data e a hora atuais nos registradores 29 a 35: ano, mês − 1 (janeiro = 0), dia, dia da semana + 1, hora, minuto e segundo. O `[30,35]` só declara que esses endereços existem. Por isso eles mudam quando o 29 é lido, e ler só o 30, por exemplo, devolve o valor gravado na última leitura do 29.
- **`reset`**, apesar do nome, não reinicia o simulador: a leitura responde com o erro `SlaveFailure` (código 04), e o simulador continua atendendo os outros endereços. Serve para ver como o cliente trata uma falha do equipamento.

### Código da disciplina na string

Cada registrador da string guarda dois caracteres: o primeiro no byte alto, o segundo no byte baixo. O 25 guarda `??` e o 26 guarda `? ` (0x20 é o espaço). Para trocar `???` por `118`, o cliente escreve:

| Registrador | Caracteres | Cálculo | Valor |
|-------------|------------|---------|-------|
| 25 | `11` | 0x31 · 256 + 0x31 | 12593 |
| 26 | `8 ` | 0x38 · 256 + 0x20 | 14368 |

### Type exception

Com `"type exception": true`, o simulador recusa leituras e escritas que partem um valor de vários registradores: ler só o 4, metade de um `float32`, ou escrever só o 25, que está no meio da string, responde `IllegalAddress`. Como o cliente desta aula lê e escreve um registrador por vez, o arquivo usa `false`.

No pymodbus 3.7.2, com `true`, uma leitura que começa na string e passa do fim dela (por exemplo, 17 registradores a partir do 11) trava o simulador, que para de responder a todos os clientes.

### Blocos compartilhados

Com `"shared blocks": true`, as quatro tabelas do MODBUS usam a mesma memória. O holding register 1 e o input register 1 são a mesma posição: o que o cliente escreve num aparece no outro.

Coils e discrete inputs também ficam nessa memória, 16 por registrador. O coil de número `n` está no registrador `n // 16`, no bit `n % 16`. Por isso o registrador 10 guarda os coils de 160 a 175: escrever `True` no coil 161 muda o registrador 10 para 2 (bit 1 ligado).

Com `"shared blocks": false`, cada tabela teria a sua própria memória, como no servidor desta aula.

## Preparar o ambiente

Com o cmd aberto na pasta `Python 5/SimulatorServerMODBUS`, crie o ambiente `.venv`:

```bat
python -m venv .venv
```

Ative o ambiente:

```bat
.venv\Scripts\activate
```

Instale as bibliotecas listadas em `requirements.txt` (pymodbus com o extra `simulator`, que traz o aiohttp usado pela página web):

```bat
pip install -r requirements.txt
```

A criação do ambiente e a instalação só são necessárias na primeira vez.

## Executar

Com o ambiente ativado:

```bat
python main.py
```

O simulador imprime o endereço MODBUS e o da página web, e fica rodando até a janela ser fechada ou `Ctrl+C` ser pressionado. Com ele no ar, abra **outro** cmd e execute o cliente, como descrito no README de `Python 5/ClienteMODBUS`.

Para testar com o cliente:

- Escreva no **holding register 1** (opção 2, tipo 1) e depois leia o **input register 1** (opção 1, tipo 3): o valor é o mesmo, porque os blocos são compartilhados.
- Escreva 1 no **coil 161** (opção 2, tipo 2) e depois leia o **holding register 10** (opção 1, tipo 1): o valor passa a ser 2.
- Leia o **holding register 3** várias vezes (opção 1, tipo 1, com várias leituras): o valor muda a cada leitura. Tente escrever nele: o simulador responde com erro, porque ele não está em `write`.
- Leia o **holding register 27** várias vezes: o contador sobe 1 a cada leitura.
- Leia o **holding register 29** e depois os registradores de 30 a 35: aparecem a data e a hora do momento da leitura do 29.
- Escreva **12593** no holding register 25 e **14368** no 26: o código da disciplina passa a ser "ENE118". Para ver o texto montado, use a página web do simulador.
- Leia o **holding register 36**: o simulador responde com `SlaveFailure`.
- Leia o **holding register 37**: o simulador responde com `IllegalAddress`, porque esse endereço não está no `setup.json`.

O simulador foi testado com o pymodbus 3.7.2, a versão do `requirements.txt`. A partir da versão 3.9, a documentação do pymodbus avisa que este simulador será substituído por outro na versão 4.0.
