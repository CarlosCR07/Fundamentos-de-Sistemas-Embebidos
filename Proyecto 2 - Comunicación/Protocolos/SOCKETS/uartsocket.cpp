#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#define DEVICE_PORT "/dev/ttyACM0"
#define BAUD_RATE 9600
#define SERVER_IP "192.168.1.77" // Reemplazar con la IP del servidor
#define PORT 8888

int main(int argc, char **argv) {
    if (wiringPiSetup() == -1) {
        cerr << "Failed to initialize WiringPi library" << endl;
        return 1;
    }

    int fd_comm = serialOpen(DEVICE_PORT, BAUD_RATE);
    if (fd_comm == -1) {
        cerr << "Failed to open UART communication" << endl;
        return 1;
    }
    cout << "UART communication successfully setup" << endl;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    cout << "Connected to server" << endl;

    int N = 1000; // Número de iteraciones
    char received_data;

    for (int i = 0; i < N; i++) {
        received_data = serialGetchar(fd_comm);
        if (received_data != -1) {
            send(sock, &received_data, sizeof(received_data), 0);
        }
    }

    serialClose(fd_comm);
    close(sock);

    return 0;
}

