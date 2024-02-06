import matplotlib.pyplot as plt

# Lista para almacenar los datos
data = []

# Lee los datos desde el archivo de texto
with open('PYxRes.txt', 'r') as file:
    for line in file:
        data.append(float(line.strip()))

# Crea una lista de índices para el eje x
x = list(range(len(data)))

# Crea el gráfico de espiga
plt.plot(x, data, marker='|', linestyle='-', color='b')

# Configura las etiquetas del eje x
plt.xticks(x, [str(i) for i in x])

# Configura el título y las etiquetas de los ejes
plt.title('Histograma Lenguaje Python')
plt.xlabel('Índice')
plt.ylabel('Valor')

# Muestra el gráfico
plt.show()



