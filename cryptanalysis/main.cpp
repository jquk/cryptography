#include <iostream>
#include "message.h"

int main()
{
    const std::string myString = "hello world";
    Message message = Message(&myString);

    // message data
    const message_t messageMetadata = message.getMessageMetadata();
    uint8_t numberOfUniqueCharacters = message.getNumberOfUniqueCharacters();
    std::cout << "message: " << std::endl \
    << "message: " << messageMetadata.message << std::endl \
    << "message.numberOfUniqueCharacters: " << unsigned(numberOfUniqueCharacters) << std::endl \
    << std::endl;

    return EXIT_SUCCESS;
}