#include <string>

class Atbash {
public:
    // initialize
    Atbash();
    Atbash(int key);
    Atbash(const std::string *message);
    Atbash(const std::string *message, int key);

    // encryption related functions
    void encrypt(const std::string *message);// receives an input for encryption
    void encrypt(const std::string *message, int key);// receives an input for encryption
    const std::string getEncryptedMessage();

    // decryption related functions
    void decrypt(const std::string *message);// receives an input for decryption
    const std::string getDecryptedMessage();

    void setKey(int key);
    int getKey();

private:
    const std::string m_inputMessage;
    std::string m_encryptedMessage;
    int m_key = 0;

    // AtbashEncryption m_atbashEncryption;// = new AtbashEncryption();
    bool validateInput();
    const char alphabet[50] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };
    int alphabetLenght = sizeof(alphabet);
    // AtbashEncryption atbashEncryption();
    // AtbashDecryption atbashDecryption();
};
