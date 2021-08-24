#include <string>
#include <iostream>
#include "atbash.h"

int main()
{
    const std::string message = "HELLO WORLD";
    std::cout << "main: " << std::endl << " - Original message:" << std::endl << "  - Length: " << message.length() << std::endl << "  - Message: " << message << std::endl << "  - Message[0]: " << message[0] << std::endl;

    // Atbash *atbash = new Atbash();
    Atbash atbash;
    // std::string key = "CDEFGHIJKLMNOPQRSTUVWXYZ0123456789AB";
    // atbash.setKey(key);
    atbash.encrypt(&message);

    std::string encryptedMessage = atbash.getEncryptedMessage();
    std::cout << " - Encrypted message: " << std::endl << "  - Message: " << encryptedMessage << std::endl << "  - Length: " << encryptedMessage.length() << std::endl << "  - Encryption Key: \"" << atbash.getKey() << "\"" << std::endl;

    return 0;
}
