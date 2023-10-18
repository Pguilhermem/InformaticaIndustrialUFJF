import threading
import time


def contador(inicio, fim):
    for i in range(inicio, fim):
        print(f'Thread {threading.current_thread().name}: {i}')
        time.sleep(0.2)  # simula uma instrução bloqueante


# Execução sem a utilização de threads
print("Execução sem threads - Sequencial")
ti = time.perf_counter()
contador(0, 5)
contador(5, 10)
print(f"Tempo gasto: {time.perf_counter()-ti} segundos")


# Execução com a utilização de threads
print("Execução com threads - Concorrente")
ti = time.perf_counter()
t1 = threading.Thread(target=contador, args=(0, 5), name='T1')
t2 = threading.Thread(target=contador, args=(5, 10), name='T2')
t1.start()
t2.start()
t1.join()
t2.join()
print(f"Tempo gasto: {time.perf_counter()-ti} segundos")
