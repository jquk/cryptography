#include <string>
#include "atbash_Cfg.h"

class Atbash {
public:
    // initialize
    Atbash();
    Atbash(std::string key);
    Atbash(const std::string *message);
    Atbash(const std::string *message, std::string key);

    // encryption related functions
    void encrypt(const std::string *message);// receives an input for encryption
    void encrypt(const std::string *message, std::string key);// receives an input for encryption
    const std::string getEncryptedMessage();

    // decryption related functions
    void decrypt(const std::string *message);// receives an input for decryption
    const std::string getDecryptedMessage();

    void setKey(std::string key);
    std::string getKey();

private:
    const std::string m_inputMessage;
    std::string m_encryptedMessage;
    std::string m_substitutionKey = atbash_Cfg_substitutionKey;
    bool validateInputMessage(std::string message);
    bool validateSubstitutionKey(std::string key);
    const std::string alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    uint8_t alphabetLenght = alphabet.length();
};
