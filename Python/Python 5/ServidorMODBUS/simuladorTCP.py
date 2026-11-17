"""
Simulador MODBUS TCP com a classe ModbusSimulatorServer do pymodbus

A tabela de dados e a comunicação são descritas no arquivo setup.json:
- HR1000: valor aleatório entre 380 e 419, sorteado a cada leitura (ação "random")
- HR2000: livre para o cliente escrever
- Coil 1000: livre para o cliente escrever

Com "shared blocks": true, coils e registradores ficam na mesma memória e cada
registrador guarda 16 coils. O coil 1000 fica no registrador 62 (1000 // 16 = 62),
por isso o setup.json declara o endereço 62 como "bits" e o libera em "write".

Além do MODBUS na porta 502, o simulador abre uma página web em
http://localhost:8080 onde dá para ver e alterar os registradores.

Requer: pip install "pymodbus[simulator]==3.7.2"
"""
import asyncio
from pathlib import Path

from pymodbus.server import ModbusSimulatorServer

# setup.json fica na mesma pasta deste arquivo
ARQUIVO_JSON = Path(__file__).parent / "setup.json"


async def main():
    simulador = ModbusSimulatorServer(
        modbus_server="servidor",      # nome em "server_list" no setup.json
        modbus_device="equipamento",   # nome em "device_list" no setup.json
        http_host="localhost",
        http_port=8080,
        json_file=str(ARQUIVO_JSON),
    )
    print("Simulador MODBUS em execução em localhost:502")
    print("Página web do simulador: http://localhost:8080")
    await simulador.run_forever()


if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("Simulador encerrado")
