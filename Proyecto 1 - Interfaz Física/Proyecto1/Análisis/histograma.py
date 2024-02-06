import matplotlib.pyplot as plt

# Nombre del archivo de texto
nombre_archivo = 'CppxRes.txt'

# Lista para almacenar los valores del archivo
valores = []

# Leer los valores del archivo y almacenarlos en la lista
with open('CppxRes.txt', 'r') as archivo:
    for linea in archivo:
        valor = float(linea.strip())  # Convierte la línea en un número de punto flotante
        valores.append(valor)

# Crear el histograma de frecuencias
plt.hist(valores, bins=10, edgecolor='k')  # Puedes ajustar el número de bins según tus necesidades
plt.xlabel('Valores')
plt.ylabel('Frecuencia')
plt.title('Histograma de Frecuencias Lenguaje C++')
plt.grid(True)

# Mostrar el histograma
plt.show()
