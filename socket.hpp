#include <iostream>
#include <netinet/in.h> // gives access to listen, accept, address, AF_INET, INADDR_ANY, etc.
#include <string.h> // gives memset: sets memory at pointer location


class Socket {
    private:
        const int socketId;
        const struct sockaddr_in sAddress;

        struct sockaddr_in socketAddress(int PORT) {
            struct sockaddr_in address;

            memset((char*)&address, 0, sizeof(address));
            address.sin_family = AF_INET;
            address.sin_addr.s_addr= htonl(INADDR_ANY);
            address.sin_port = htons(PORT);

            if (bind(socketId, (const struct sockaddr*)&address, sizeof(address)) < 0) exit(0);

            std::cout << "Socket created on port: " << PORT << std::endl;        
            return address;
        }

    public:
        Socket(int PORT) :
            socketId(socket(AF_INET, SOCK_STREAM, 0)),
            sAddress(this->socketAddress(PORT))
            {}

        int getId() {
            return this->socketId;
        }
        struct sockaddr_in getAddress() {
            return this->sAddress;
        }
};