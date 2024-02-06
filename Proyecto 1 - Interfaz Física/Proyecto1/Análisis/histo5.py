import matplotlib.pyplot as plt

# Listas para almacenar los datos
x = []  # Eje x
data = []  # Eje y

# Lee los datos desde el archivo de texto
with open('CxRes.txt', 'r') as file:
    for line in file:
        value = float(line.strip())
        data.append(value)
        x.append(value)

# Crea el gráfico de espiga
plt.plot(x, data, marker='|', linestyle='-', color='b')

# Configura las etiquetas del eje x
plt.xticks(x, [str(value) for value in x])

# Configura el título y las etiquetas de los ejes
plt.title('Gráfico de Espiga')
plt.xlabel('Valor')
plt.ylabel('Valor')  # Puedes ajustar el título del eje y si lo deseas

# Muestra el gráfico
plt.show()
