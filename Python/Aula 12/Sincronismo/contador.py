from ast import arg
import threading


class Contador():
    def __init__(self, nthreads, maxcont):
        self._cont = 0
        self._maxcont = maxcont
        self._threadPool = []
        self._nthreads = nthreads
        self._lock = threading.Lock()

    def increment(self):
        n = 0
        self._lock.acquire()
        while n < self._maxcont:
            self._cont += 1
            n +=1
        self._lock.release()
    
    def run(self):
        for t in range(0,self._nthreads):
            self._threadPool.append(threading.Thread(target=self.increment))
            self._threadPool[t].start()
        for th in self._threadPool:
            th.join()
        print(f'Resultado obtido: {self._cont} | Resultado esperado: {self._nthreads*self._maxcont} ')
        

