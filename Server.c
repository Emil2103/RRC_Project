#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include "RRCConnectionSetupRequest.h"
#include "RRCConnectionSetupComplete.h"
#include "MessageType.h"
#include "OCTET_STRING.h"


#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    ssize_t bytes_received;
    RRCConnectionSetupRequest_t rrcSetupRequest;

    // Создание сокета
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Настройка параметров сервера
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Привязка сокета к адресу и порту
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Ожидание подключения клиента
    if (listen(sockfd, 5) == -1) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    client_len = sizeof(client_addr);

    // Принятие подключения от клиента
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
        perror("Acceptance failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Получение сообщения от клиента
    bytes_received = recv(newsockfd, &rrcSetupRequest, sizeof(RRCConnectionSetupRequest_t), 0);
    if (bytes_received == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    printf("Received RRC Connection Setup Request from client\n");

    // Декодирование полученного сообщения
    // Напишите код для декодирования данных в структуру rrcSetupRequest

    // Вывод содержимого структуры
    printf("MessageType: %d\n", rrcSetupRequest.messageHeader.messageType);
    printf("MessageLength: %d\n", rrcSetupRequest.messageHeader.messageLenght);
    // Вывод остальных данных структуры RRCConnectionSetupRequest
    printf("mmeUEIdentity: ");
    for (int i = 0; i < rrcSetupRequest.mmeUEIdentity.size; i++) {
        printf("%02X", rrcSetupRequest.mmeUEIdentity.buf[i]);
        printf("%d", rrcSetupRequest.mmeUEIdentity.size);
    }
    printf("\n");

    printf("sTMSI: ");
    for (int i = 0; i < rrcSetupRequest.sTMSI.size; i++) {
        printf("%02X ", rrcSetupRequest.sTMSI.buf);
    }
    printf("\n");

    printf("cellIdentify: ");
    for (int i = 0; i < rrcSetupRequest.cellIdentify.size; i++) {
        printf("%02X ", rrcSetupRequest.cellIdentify.buf);
    }
    printf("\n");
    

    // Формирование и отправка ответа RRC Connection Setup Complete
    RRCConnectionSetupComplete_t rrcSetupComplete;
    rrcSetupComplete.messageHeader.messageType = MessageType_rrcConnectionSetupComplete;
    rrcSetupComplete.messageHeader.messageLenght = sizeof(RRCConnectionSetupComplete_t);
    rrcSetupComplete.integrityProtectionAlgorithm = 1;

    send(newsockfd, &rrcSetupComplete, sizeof(RRCConnectionSetupComplete_t), 0);
    printf("RRC Connection Setup Complete sent to client\n");

    close(newsockfd);
    close(sockfd);
    return 0;
}

