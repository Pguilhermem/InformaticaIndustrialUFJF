from pymodbus.datastore import ModbusSequentialDataBlock, ModbusSparseDataBlock, ModbusServerContext, ModbusSlaveContext
from pymodbus.server import StartTcpServer
from pymodbus.server import ModbusTcpServer
from threading import Thread
from time import sleep
import random

class ServidorMODBUS():
    """
    Classe Servidor MODBUS
    """
    def __init__(self, host_ip,port):
        """
        Construtor da classe ServidorMODBUS
        :param host_ip: Endereço IP de execução do servidor modbus.
        :param port: Porta de comunicação do servidor modbus.
        """

        self._db = ModbusSlaveContext(
            co=ModbusSequentialDataBlock(0, [False] * 1000),
            di=ModbusSequentialDataBlock(0, [False] * 1000),
            ir=ModbusSequentialDataBlock(0, [0] * 1000),
            hr=ModbusSequentialDataBlock(0, [0] * 2000),
            zero_mode=True,
        )
        contexto = ModbusServerContext(slaves=self._db, single=True)

        # Por dentro, StartTcpServer chama asyncio.run, cria um
        # ModbusTcpServer e espera serve_forever(). 
        self._server = Thread(
            target=StartTcpServer,
            kwargs={"context": contexto, "address": (host_ip, port)},
            daemon=True,
        )
    
    def run(self):
        """
        Execução do servidor Modbus
        """
        self._server.start()
        print("Servidor em execução")
        while True:
            
            self._db.setValues(3, 1000,[random.randrange(400,500)]) # temperatura
            self._db.setValues(3, 1001,[random.randrange(100000,120000)]) #pressão  -> VAI GERAR ERRO NO ENVIO PARA O CLIENTE, valor precisa ser menor que 65535
            self._db.setValues(3, 1002,[random.randrange(20,40)]) # umidade
            self._db.setValues(3, 1003,[random.randrange(40,100)]) # consumo
            sleep(1)
            
        



