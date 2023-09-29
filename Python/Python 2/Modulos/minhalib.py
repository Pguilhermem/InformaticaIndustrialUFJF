# Cria funções que podem ser utilizadas em outros codigos
def soma(op1: int, op2: int) -> int:  # Os comentarios Entre """....""" aparecem ao se digitar a função no arquivo .py, possibilitando outros programadores terem uma breve impressão a utilização da função
    """ 
    Função que retorna a soma de dois números
    :param op1: primeiro operando
    :param op2: segundo operando
    :return : soma dos operandos
    """
    return op1+op2


def divisao(dividendo, divisor):
    """
    Função que retorna a divisão do dividendo pelo divisor
    :param dividendo: dividendo da operação
    :param divisor: divisor da operação
    :return : divisão do dividendo pelo divisor
    """
    return dividendo/divisor


# Cria uma lista desse tipo:[0,1,4,9,16,25,...,100]
lista = [x**2 for x in range(0, 10)]


if __name__ == "__main__":  # Não são executadas quando se o utiliza o import
    import sys
    if sys.argv[3] == "+":
        print(soma(float(sys.argv[1]), float(sys.argv[2])))
    elif sys.argv[3] == "/":
        print(divisao(float(sys.argv[1]), float(sys.argv[2])))
    else:
        print("Operação inválida")
