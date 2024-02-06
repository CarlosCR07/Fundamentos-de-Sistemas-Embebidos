#include <iostream>
#include <fstream>
#include <unistd.h>
#include <wiringPi.h>

#define GPIO_0 27
#define GPIO_1 22
#define GPIO_2 23
#define GPIO_3 24
#define GPIO_4 5
#define GPIO_5 6
#define GPIO_6 13
#define GPIO_7 25

void configurarPines() {
    // Se inicializa wiringPi y se indica el uso de los pines de forma directa
    wiringPiSetupGpio(); 
    // Configurar los pines GPIO como entradas
    pinMode(GPIO_0, INPUT);
    pinMode(GPIO_1, INPUT);
    pinMode(GPIO_2, INPUT);
    pinMode(GPIO_3, INPUT);
    pinMode(GPIO_4, INPUT);
    pinMode(GPIO_5, INPUT);
    pinMode(GPIO_6, INPUT);
    pinMode(GPIO_7, INPUT);
    std::cout << "Configuración de pines realizada." << std::endl;
}

void cerrarPines() {
    // No es necesario en wiringPi
    std::cout << "Pines GPIO cerrados y limpiados." << std::endl;
}

void leerValores() {
    std::ofstream xFile("x.txt"); // Abrir archivos para escritura
    std::ofstream yFile("y.txt");

    for (int i = 0; i < 10000; i++) { // Se realizan 10000 iteraciones
        int valores[8] = { //Lectura de los pines declarados al inicio 
            digitalRead(GPIO_0), digitalRead(GPIO_1), digitalRead(GPIO_2), digitalRead(GPIO_3),
            digitalRead(GPIO_4), digitalRead(GPIO_5), digitalRead(GPIO_6), digitalRead(GPIO_7)
        };

        int numero = 0;
        for (int j = 0; j < 8; j++) { //Se recorre el arreglo de valores leídos y se suman entre sí
            numero += valores[j];
        }

        timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts); //Se obtiene el tiempo en este puento del programa
        // Se calcula el tiempo en segundos con milisegundos
        double timestamp_seconds = static_cast<double>(ts.tv_sec) + static_cast<double>(ts.tv_nsec) / 1000000000.0;
        xFile << std::fixed << std::setprecision(6) << timestamp_seconds << std::endl; //Se guarda el tiempo en el archivo "x"

        yFile << numero << std::endl; // Se guarda el resultado de la suma en el archivo "y"
        usleep(1); // Esperar 1 microsegundo
    }
    // Cerrar los archivos
    xFile.close();
    yFile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 2) { //Más de un comando o ningún comando recibido
        std::cout << "Uso: " << argv[0] << " [config|cerrar|valor]" << std::endl;
        return 2;
    }

    std::string command = argv[1]; //Obtenemos el comando recibido

    if (command == "config") { // Comando de configuración
        configurarPines();
    } else if (command == "cerrar") { // Comando de cierre
        cerrarPines();
    } else if (command == "valor") { // Comando para obtención de valores
        leerValores();
    } else {
        std::cout << "Comando no reconocido. Los comandos válidos son: config, cerrar, valor" << std::endl;
        return 2;
    }

    return 0;
}
