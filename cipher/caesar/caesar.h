#include <string>
#include "caesar_Cfg.h"

class Caesar {
public:
    // initialize
    Caesar();
    Caesar(const int key);
    Caesar(const std::string *message);
    Caesar(const std::string *message, const int key);

    // encryption related functions
    void encrypt(const std::string *message);// receives an input for encryption
    void encrypt(const std::string *message, const int key);// receives an input for encryption
    const std::string getEncryptedMessage();

    // decryption related functions
    void decrypt(const std::string *message);// receives an input for decryption
    const std::string getDecryptedMessage();

    void setKey(const int key);
    const int getKey();

private:
    const std::string m_inputMessage;
    std::string m_encryptedMessage;
    int m_shiftKey = caesar_Cfg_shiftKey;
    bool validateInputMessage(std::string message);
    bool validateSubstitutionKey(const int key);
    const std::string alphabet = caesar_Cfg_alphabet;
    uint8_t alphabetLenght = alphabet.length();
};
