#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include "RRCConnectionSetupRequest.h"
#include "MessageType.h"
#include "OCTET_STRING.h"
#include "der_encoder.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Создание сокета
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Настройка параметров сервера
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) == -1) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Подключение к серверу
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    // Создание и отправка сообщения RRC Connection Setup Request
    RRCConnectionSetupRequest_t rrcSetupRequest;
    rrcSetupRequest.messageHeader.messageType = MessageType_rrcConnectionSetupRequest;
    rrcSetupRequest.messageHeader.messageLenght = sizeof(RRCConnectionSetupRequest_t);
    // Выделяем память для массива buf в mmeUEIdentity
    rrcSetupRequest.mmeUEIdentity.buf = (uint8_t *)malloc(2 * sizeof(uint8_t)); // Выделяем память под 2 байта
    if (rrcSetupRequest.mmeUEIdentity.buf == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    // Устанавливаем размер size и заполняем массив buf
    rrcSetupRequest.mmeUEIdentity.size = 1;
    rrcSetupRequest.mmeUEIdentity.buf[0] = 0xAB;


    rrcSetupRequest.sTMSI.buf = (uint8_t *)malloc(2 * sizeof(uint8_t)); // Выделяем память под 2 байта
    if (rrcSetupRequest.sTMSI.buf == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Устанавливаем размер size и заполняем массив buf
    rrcSetupRequest.sTMSI.size = 1;
    rrcSetupRequest.sTMSI.buf[0] = 0xEF;


    // Выделяем память для массива buf в cellIdentify
    rrcSetupRequest.cellIdentify.buf = (uint8_t *)malloc(2 * sizeof(uint8_t)); // Выделяем память под 2 байта
    if (rrcSetupRequest.cellIdentify.buf == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Устанавливаем размер size и заполняем массив buf
    rrcSetupRequest.cellIdentify.size = 1;
    rrcSetupRequest.cellIdentify.buf[0] = 0x34;


    // Отправка сообщения на сервер
    if (send(sockfd, &rrcSetupRequest, sizeof(RRCConnectionSetupRequest_t), 0) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
    printf("RRC Connection Setup Request sent to server\n");


    sleep(800);
    close(sockfd);
    return 0;
}


