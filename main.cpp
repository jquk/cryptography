#include <string>
#include <iostream>
#if (CIPHER_COMPILATION_TARGET==CAESAR)
#include "cipher/caesar/caesar.h"
#elif (CIPHER_COMPILATION_TARGET==ATBASH)
#include "cipher/atbash/atbash.h"
#endif

#if !defined(CIPHER_COMPILATION_TARGET)
#error "CIPHER_COMPILATION_TARGET is not defined"
#endif

int main()
{

#if (CIPHER_COMPILATION_TARGET==CAESAR)
// #pragma message "CAESAR CIPHER"
   const std::string message = "XYZ";

    std::cout << "main: " << std::endl;
	std::cout << " * Original message:" << std::endl << "  - Length: " << message.length() << std::endl << "  - Content: " << message << std::endl << "  - Message[0]: " << message[0] << std::endl;

    Caesar caesar;
    caesar.encrypt(&message);

    std::string encryptedMessage = caesar.getEncryptedMessage();
    std::cout << " * Encrypted message: " << std::endl << "  - Length: " << encryptedMessage.length() << std::endl << "  - Content: " << encryptedMessage << std::endl << "  - Length: " << encryptedMessage.length() << std::endl << "  - Encryption Key: \"" << caesar.getKey() << "\"" << std::endl;

#elif (CIPHER_COMPILATION_TARGET==ATBASH)
// #pragma message "ATBASH CIPHER"
    const std::string message = "ABC DEF";

    std::cout << "main: " << std::endl;
	std::cout << " * Original message:" << std::endl << "  - Length: " << message.length() << std::endl << "  - Content: " << message << std::endl << "  - Message[0]: " << message[0] << std::endl;

    // Atbash *atbash = new Atbash();
    Atbash atbash;
    // std::string key = "CDEFGHIJKLMNOPQRSTUVWXYZ0123456789AB";
    // atbash.setKey(key);
    atbash.encrypt(&message);

    std::string encryptedMessage = atbash.getEncryptedMessage();
    std::cout << " * Encrypted message: " << std::endl << "  - Length: " << encryptedMessage.length() << std::endl << "  - Content: " << encryptedMessage << std::endl << "  - Length: " << encryptedMessage.length() << std::endl << "  - Encryption Key: \"" << atbash.getKey() << "\"" << std::endl;
#else
    std::cout << "NO COMPILATION TARGET SPECIFIED" << std::endl;
#endif
    return EXIT_SUCCESS;
}//main