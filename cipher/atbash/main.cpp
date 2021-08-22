#include <string>
#include <iostream>
#include "atbash.h"

int main()
{
    const std::string message = "HELLO WORLD";
    std::cout << "atbash::encrypt(): " << "message.length(): " << message.length() << ", message: " << message << ", message[0]: " << message[0] << std::endl;

    // Atbash *atbash = new Atbash();
    Atbash atbash;
    int key = 1;
    atbash.setKey(key);
    atbash.encrypt(&message);

    std::cout << "main::atbash.getEncryptedMessage(): " << atbash.getEncryptedMessage() << std::endl;
    std::cout << "main::atbash.getKey(): " << atbash.getKey() << std::endl;

    return 0;
}
