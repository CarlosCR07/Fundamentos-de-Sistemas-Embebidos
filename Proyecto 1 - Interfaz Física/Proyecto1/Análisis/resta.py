#CALCULA LOS DELTA T (t1-t0, ..., tn+1 - tn)

# Abre el archivo de entrada para lectura
with open('Cx.txt', 'r') as archivo_entrada:
    lineas = archivo_entrada.readlines()

# Inicializa una lista para almacenar los resultados
resultados = []

# Itera a través de las líneas y realiza las restas
for i in range(len(lineas) - 1):
    valor1 = float(lineas[i].strip())  # Lee el valor de la primera columna en el renglón i
    valor2 = float(lineas[i + 1].strip())  # Lee el valor de la primera columna en el renglón i+1
    resultado = valor2 - valor1
    resultados.append(resultado)

# Abre un archivo nuevo para escribir los resultados
with open('CxRes.txt', 'w') as archivo_salida:
    # Escribe los resultados en forma de columna
    for resultado in resultados:
        archivo_salida.write(f'{resultado}\n')
