# Importación de módulos:
import RPi.GPIO as GPIO
import time

# Definición de pines GPIO utilizados
GPIO_0 = 27
GPIO_1 = 22
GPIO_2 = 23
GPIO_3 = 24
GPIO_4 = 5
GPIO_5 = 6
GPIO_6 = 13
GPIO_7 = 25

# Configuración de pines GPIO
def configurar_pines():
    GPIO.setmode(GPIO.BCM)  # Establece el modo de pines en BCM
    pines = [GPIO_0, GPIO_1, GPIO_2, GPIO_3, GPIO_4, GPIO_5, GPIO_6, GPIO_7]

    for pin in pines:
        GPIO.setup(pin, GPIO.IN)  # Configura el pin como entrada

# Cierre y limpieza de pines GPIO
def cerrar_pines():
    GPIO.cleanup()  # Limpia y cierra los pines configurados

# Lectura de valores de pines GPIO y registro
def leer_valores():
    try:
        with open('x.txt', 'w') as x_file, open('y.txt', 'w') as y_file:
            for _ in range(10000):  # Realiza 10,000 lecturas
                valores = [GPIO.input(pin) for pin in [GPIO_0, GPIO_1, GPIO_2, GPIO_3, GPIO_4, GPIO_5, GPIO_6, GPIO_7]]
                numero = sum(valores)  # Suma de valores en alto (1)
                timestamp = time.time()  # Obtiene la marca de tiempo actual
                x_file.write('%s\n' % timestamp)  # Escribe la marca de tiempo en 'x.txt'
                y_file.write(f'{numero}\n')  # Escribe el número de pines en alto en 'y.txt'
                time.sleep(0.000001)  # Espera 1 microsegundo
    except KeyboardInterrupt:
        pass

if __name__ == '__main__':
    import sys

    if len(sys.argv) != 2:
        print("Uso: python programa.py [config|cerrar|valor]")
        sys.exit(2)

    if sys.argv[1] == 'config':
        configurar_pines()  # Configura los pines GPIO
    elif sys.argv[1] == 'cerrar':
        cerrar_pines()  # Limpia y cierra los pines GPIO
    elif sys.argv[1] == 'valor':
        leer_valores()  # Lee valores de los pines y registra
    else:
        print("Comando no reconocido. Los comandos válidos son: config, cerrar, valor")
        sys.exit(2)
