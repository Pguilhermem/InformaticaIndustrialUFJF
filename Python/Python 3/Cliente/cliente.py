import socket

class Cliente():
    """
    Classe Cliente - API Socket
    """
    def __init__(self, server_ip, port):
        """
        Construtor da classe Cliente
        """
        self.__server_ip = server_ip
        self.__port = port
        self.__tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    
    def start(self):
        """
        Método que inicializa a execução do Cliente
        """
        endpoint = (self.__server_ip,self.__port)
        try:
            self.__tcp.connect(endpoint)
            print("Conexão realizada com sucesso!")
            self.__method()
        except:
            print("Servidor não disponível")

    
    def __method(self):
        """
        Método que implementa as requisições do cliente
        """
        try:
            msg = ''
            while True:
                msg = input("Digite a operação (x para sair): ")
                if msg == '':
                    continue
                elif msg == 'x':
                    break
                self.__tcp.send(bytes(msg,'ascii'))
                resp = self.__tcp.recv(1024)
                print("= ",resp.decode('ascii'))
            self.__tcp.close()
        except Exception as e:
            print("Erro ao realizar comunicação com o servidor", e.args)
