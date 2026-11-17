from pymodbus.datastore import ModbusSequentialDataBlock, ModbusSparseDataBlock, ModbusServerContext, ModbusSlaveContext
from pymodbus.server import StartTcpServer
from pymodbus.server import ModbusTcpServer
from threading import Thread
import random
from time import sleep


class ServidorMODBUS():
    """
    Classe Servidor MODBUS
    """
    
    def __init__(self, host_ip, port):
        """
        Construtor da classe ServidorMODBUS
        :param host_ip: Endereço IP de execução do servidor MODBUS.
        :param port: Porta de comunicação do servidor MODBUS.
        """
        self._db = ModbusSlaveContext(
            co=ModbusSequentialDataBlock(1000, [False] * 1000),
            di=ModbusSequentialDataBlock(0, [False] * 1000),
            ir=ModbusSequentialDataBlock(0, [0] * 1000),
            hr=ModbusSparseDataBlock({1000:0,2000:[0]*1000}),
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
        try:
            self._server.start()
            print("Servidor MODBUS em execução")
            while True:
                # fc_as_hex, nas funções set e get do banco de dados, se refere ao tipo de registrador:
                # 1: coil, 2: discrete, 3: holding register, 4: input register
                self._db.setValues(3,1000,[random.randrange(int(0.95*400),int(1.05*400))])
                print('======================')
                print("Tabela MODBUS")
                print(f'Holding Register \r\n R1000: {self._db.getValues(3,1000)} \r\n R2000: {self._db.getValues(3,2000)}')
                print(f'Coil \r\n R1000: {self._db.getValues(1,1000)}')
                sleep(1)
        except Exception as e:
            print("Erro: ",e.args)



    

