import pandas as pd
import matplotlib.pyplot as plt

print("Ejecutand Código ...")

# Leer el archivo y crear un DataFrame
nombre_archivo = 'CppxRes.txt'
df = pd.read_csv(nombre_archivo, header=None, names=['Valores'])

# Encontrar los valores repetidos
valores_repetidos = df[df.duplicated(keep=False)]

# Crear un scatter plot con los valores repetidos
plt.figure(figsize=(10, 6))
plt.scatter(valores_repetidos['Valores'], valores_repetidos.index.value_counts(), s=100, c='blue', marker='^')
plt.xlabel('Valores')
plt.ylabel('Frecuencia')
plt.title('Δt Repetidas - Histograma - Lenguaje C++')
plt.xticks(rotation=45)
plt.grid()

# Mostrar el gráfico
plt.tight_layout()
plt.show()
