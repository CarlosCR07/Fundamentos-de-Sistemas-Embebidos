#include <iostream>
#include <fstream>
#include <wiringPi.h>
#include <wiringSerial.h> // Para la comunicación UART

using namespace std;

#define DEVICE_PORT "/dev/ttyACM0" // Puerto UART predeterminado en Raspberry Pi
#define BAUD_RATE 9600 // Velocidad de baudios para la comunicación UART

int main (int argc, char **argv)
{
  // Inicializar la biblioteca WiringPi y el puerto UART
  if (wiringPiSetup() == -1) {
    cerr << "Failed to initialize WiringPi library" << endl;
    return 1;
  }
  
  int fd_comm = serialOpen(DEVICE_PORT, BAUD_RATE); // Abrir el puerto serie UART

  if (fd_comm == -1) {
    cerr << "Failed to open UART communication" << endl;
    return 1;
  }
  cout << "UART communication successfully setup" << endl;

  ofstream yfile;
  yfile.open("y.txt");

  ofstream timeFile;
  timeFile.open("timeFile.txt");

  int N = 1000; // Numero de iteraciones

  for (int i = 0; i < N; i++) {
    int received_data = serialGetchar(fd_comm); // Leer un carácter del UART
    if (received_data != -1) {
      timespec ts;
      clock_gettime(CLOCK_REALTIME, &ts);
      double timestamp_seconds = static_cast<double>(ts.tv_sec) + static_cast<double>(ts.tv_nsec) / 1000000000.0;
      timeFile << std::fixed << timestamp_seconds << endl;
      yfile << received_data << "\n";
    }
  }

  yfile.close();
  timeFile.close();

  serialClose(fd_comm); // Cerrar el puerto serie UART

  return 0;
}

