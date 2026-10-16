import threading
import time


class ContaBancaria:
    """
    Quando o lock é utilizado, há a sincronização entre as threads do método disparar_ordens
    Quando ele não é utilizado, há uma condição de corrida que deixa o comportamento do sistema inconsistente
    """

    def __init__(self, saldo_inicial):
        """
        Construtor da classe ContaBancaria
        :param saldo_inicial: saldo da conta no momento da criação
        """

        self.saldo = saldo_inicial
        self.lock = threading.Lock()

    def transferir(self, valor):
        """
        Método que debita um valor do saldo, protegido pelo lock
        :param valor: valor a ser debitado do saldo
        """

        with self.lock:
            saldo_atual = self.saldo
            time.sleep(0.1)
            saldo_atual -= valor
            time.sleep(0.1)
            self.saldo = saldo_atual
            print(f'Transferência realizada: {valor} | Saldo atual: {self.saldo}')

        
    def disparar_ordens(self, ordens):
        """
        Método que cria uma thread de transferência para cada ordem e espera todas terminarem
        :param ordens: lista com os valores das transferências
        """
        
        thread_pool = []
        for ordem in ordens:
            thread_pool.append(threading.Thread(
                target=conta.transferir, args=(ordem,)))
            thread_pool[-1].start()
        for th in thread_pool:
            th.join()


saldo_inicial = 200

conta = ContaBancaria(saldo_inicial)

ordens_para_transferencia = [50, 70, 20, 60]

conta.disparar_ordens(ordens_para_transferencia)

print(f'Saldo final: {conta.saldo}')
