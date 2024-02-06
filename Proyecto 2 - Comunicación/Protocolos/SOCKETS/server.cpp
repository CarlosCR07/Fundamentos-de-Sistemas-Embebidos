#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main() {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char client_message;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("bind failed");
        return 1;
    }
    puts("bind done");

    listen(socket_desc, 3);

    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");

//Creamos archivo
  std::ofstream timeFile;
  timeFile.open("timeFile.txt");

    while (recv(new_socket, &client_message, sizeof(client_message), 0) > 0) {
        std::cout << "Received data from client: " << client_message << std::endl;
        timespec ts;
      	clock_gettime(CLOCK_REALTIME, &ts);
      double timestamp_seconds = static_cast<double>(ts.tv_sec) + static_cast<double>(ts.tv_nsec) / 1000000000.0;
      timeFile << std::fixed << timestamp_seconds << std::endl;
      
    }

    if (new_socket == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (new_socket == -1) {
        perror("recv failed");
    }
    
    timeFile.close();
    
    return 0;
}

