#Listas
lista = [1,2,"Guilherme",5.5,True,'a']

for x in lista:
    print(x)

lista.append("Soares")
lista[0] = 55

for x in range(0,len(lista)):
    if x == 2:
        continue
    print(lista[x])

#Dicionário
dicionario = {"curso":"Informática Industrial","númeroCréditos":4}

print(dicionario)

dicionario["curso"] = "Robótica Móvel"
dicionario["NumeroHoras"] = 60

print(dicionario)

#Tuplas

tupla = (1,2,"Guilherme",5.5,True,'a')

print()

for x in tupla:
    print(x)


#Coleções ordenadas
pilha = []

for i in range(0,10):
    pilha.append(i)

for i in range(0,10):
    print(pilha.pop(),end=" ")

print()

from collections import deque

fila = deque()

for i in range(0,10):
    fila.append(i)

for i in range(0,10):
    print(fila.popleft(),end=" ")
