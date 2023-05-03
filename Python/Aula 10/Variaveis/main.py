# Objetos imutáveis

# nome (variável)  | objeto
a = 3
b = a

print("Valor: ", a)
print("Identificador de a: ", id(a))
print("Identificador de b antes da mudança: ", id(b))
b = 4
print("Identificador de b após a mudança: ", id(b))

a += 3

print("Valor: ", a)
print("Identificador: ", id(a))

a = "Informática"

# Objetos mutáveis
# nome (variável)  | objeto
a = [1, 2, 3]
b = a
b.append(4)
print("Valor: ", a)
print("Identificador: ", id(a))
print("Identificador: ", id(b))

a.append(5)
print("Valor: ", a)
print("Identificador: ", id(a))
