#include <string>
#include <iostream>
#include "cipher/atbash/atbash.h"

#if !defined(CIPHER_COMPILATION_TARGET)
#error "CIPHER_COMPILATION_TARGET is not defined"
#endif

int main()
{

#if (CIPHER_COMPILATION_TARGET==CAESAR)
    const std::string message = "CAESAR CIPHER";
    std::cout << message << std::endl;
#elif (CIPHER_COMPILATION_TARGET==ATBASH)
    const std::string message = "ATBASH CIPHER";
    std::cout << "main: " << std::endl << " - Original message:" << std::endl << "  - Length: " << message.length() << std::endl << "  - Message: " << message << std::endl << "  - Message[0]: " << message[0] << std::endl;

    // Atbash *atbash = new Atbash();
    Atbash atbash;
    // std::string key = "CDEFGHIJKLMNOPQRSTUVWXYZ0123456789AB";
    // atbash.setKey(key);
    atbash.encrypt(&message);

    std::string encryptedMessage = atbash.getEncryptedMessage();
    std::cout << " - Encrypted message: " << std::endl << "  - Message: " << encryptedMessage << std::endl << "  - Length: " << encryptedMessage.length() << std::endl << "  - Encryption Key: \"" << atbash.getKey() << "\"" << std::endl;
#else
    std::cout << "NO COMPILATION TARGET SPECIFIED" << std::endl;
#endif
    return EXIT_SUCCESS;
}//main