#include "caesar.h"
#include <iostream>
#include <cstring>

/*
*
*/
Caesar::Caesar() { }

/*
*
*/
Caesar::Caesar(const int key) /*: m_caesarEncryption(key)*/
{
    setKey(key);
}

/*
*
*/
Caesar::Caesar(const std::string *message) /*: m_caesarEncryption(message)*/
{
    // CaesarEncryption caesarEncryption(message);
    // m_caesarEncryption = caesarEncryption;

    // m_caesarEncryption = new CaesarEncryption(message);
}

/*
*
*/
Caesar::Caesar(const std::string *message, const int key) /*: m_caesarEncryption(message, key)*/
{
    // CaesarEncryption caesarEncryption(message, m_shiftKey);
    // m_caesarEncryption = &caesarEncryption;

    // m_caesarEncryption = new CaesarEncryption(message, m_shiftKey);
}

/*------------------------ Encryption related functions ----------------------*/

/*
* receives an input for encryption
*/
void Caesar::encrypt(const std::string *message)
{
	int newIndexInAlphabet = 0;
    for (int indexInMessage = 0; indexInMessage < message->length(); indexInMessage++) {
        for (int indexInAlphabet = 0; indexInAlphabet < alphabetLenght; indexInAlphabet++) {
            if (message->at(indexInMessage) == this->alphabet.at(indexInAlphabet)) {
				// std::cout << "\n\nFound match message char and alphabet char:";
                if ((indexInAlphabet + this->m_shiftKey) >= this->alphabetLenght) {
					// std::cout << "\ncase a" << std::endl;
					newIndexInAlphabet = 0 + (this->m_shiftKey - (this->alphabetLenght - indexInAlphabet));
					// std::cout << "indexInMessage: " << indexInMessage << ", indexInAlphabet: " << indexInAlphabet << ", newIndexInAlphabet: " << newIndexInAlphabet << std::endl;
					this->m_encryptedMessage += this->alphabet.at(newIndexInAlphabet);
					// std::cout << message->at(indexInMessage) << " --> " << this->alphabet.at(newIndexInAlphabet) << std::endl;
				} else if ((indexInAlphabet + this->m_shiftKey) < 0) {
					// std::cout << "\ncase b" << std::endl;
					newIndexInAlphabet = this->alphabetLenght - this->m_shiftKey - indexInAlphabet;
					// std::cout << "indexInMessage: " << indexInMessage << ", indexInAlphabet: " << indexInAlphabet << ", newIndexInAlphabet: " << newIndexInAlphabet << std::endl;
					this->m_encryptedMessage += this->alphabet.at(newIndexInAlphabet);
					// std::cout << message->at(indexInMessage) << " --> " << this->alphabet.at(newIndexInAlphabet) << std::endl;
				} else if ((indexInAlphabet + this->m_shiftKey) < this->alphabetLenght) {
					// std::cout << "\ncase c" << std::endl;
					newIndexInAlphabet = indexInAlphabet + this->m_shiftKey;
					// std::cout << "indexInMessage: " << indexInMessage << ", indexInAlphabet: " << indexInAlphabet << ", newIndexInAlphabet: " << newIndexInAlphabet << std::endl;
					this->m_encryptedMessage += this->alphabet.at(newIndexInAlphabet);
					// std::cout << message->at(indexInMessage) << " --> " << this->alphabet.at(newIndexInAlphabet) << std::endl;
				} else {
					std::cout << "\n****case ERROR****" << std::endl;
					std::cout << "indexInMessage: " << indexInMessage << ", indexInAlphabet: " << indexInAlphabet << ", newIndexInAlphabet: " << newIndexInAlphabet << std::endl;
				}
            }
        }
    }
}

/*
* receives an input for encryption
*/
void Caesar::encrypt(const std::string *message, const int key)
{
    setKey(key);
    encrypt(message);
}

/*
*
*/
const std::string Caesar::getEncryptedMessage()
{
    return this->m_encryptedMessage;
}

/*------------------------ Decryption related functions ----------------------*/

/*
* receives an input for decryption
*/
void Caesar::decrypt(const std::string *message)
{

}

/*
*
*/
const std::string Caesar::getDecryptedMessage()
{
    return "";
}

/*------------------------ xxxxxxxxxxxxxxxxxxxxxx ----------------------*/

/*
*
*/
void Caesar::setKey(const int key)
{
    // std::cout << "caesar::setKey()::key: " << key << std::endl;
    this->m_shiftKey = key;
}

/*
*
*/
const int Caesar::getKey()
{
    return this->m_shiftKey;
}

/*
*
*/
bool Caesar::validateInputMessage(std::string message)
{
    bool retVal = true;
    if (message == "") {
        retVal = false;
    }
    /* add more conditions */
    return retVal;
}

/*
*
*/
bool Caesar::validateSubstitutionKey(const int key)
{
    // bool retVal = true;
    // if(key.length() == alphabetLenght)
    // {
    //     retVal = false;
    // }
    /* add more conditions */
    return false;
}
