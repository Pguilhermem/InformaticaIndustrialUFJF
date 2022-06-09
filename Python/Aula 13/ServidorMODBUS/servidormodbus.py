from pyModbusTCP.server import DataBank, ModbusServer
import random
from time import sleep


class ServidorMODBUS():
    """
    Classe Servidor Modbus
    """
    
    def __init__(self, host_ip, port):
        """
        Construtor
        """
        self._server = ModbusServer(host=host_ip,port=port,no_block=True)
        self._db = DataBank
        
    def run(self):
        """
        Execução do servidor Modbus
        """
        try:
            self._server.start()
            print("Servidor MODBUS em execução")
            while True:
                self._db.set_words(1000,[random.randrange(int(0.95*400),int(1.05*400))])
                print('======================')
                print("Tabela MODBUS")
                print(f'Holding Register \r\n R1000: {self._db.get_words(1000)} \r\n R2000: {self._db.get_words(2000)}')
                print(f'Coil \r\n R1000: {self._db.get_bits(1000)}')
                sleep(1)
        except Exception as e:
            print("Erro: ",e.args)



    

