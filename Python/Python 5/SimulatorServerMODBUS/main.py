import asyncio
from pathlib import Path

from pymodbus.server import ModbusSimulatorServer

ARQUIVO_JSON = Path(__file__).parent / "setup.json"


async def main():
    simulador = ModbusSimulatorServer(
        modbus_server="servidor",     
        modbus_device="equipamento",   
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
