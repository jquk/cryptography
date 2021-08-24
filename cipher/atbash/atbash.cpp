#include "atbash.h"
#include <iostream>
#include <cstring>

/*
*
*/
Atbash::Atbash() { }

/*
*
*/
Atbash::Atbash(std::string key) /*: m_atbashEncryption(key)*/
{
}

/*
*
*/
Atbash::Atbash(const std::string *message) /*: m_atbashEncryption(message)*/
{
    // AtbashEncryption atbashEncryption(message);
    // m_atbashEncryption = atbashEncryption;

    // m_atbashEncryption = new AtbashEncryption(message);
}

/*
*
*/
Atbash::Atbash(const std::string *message, std::string key) /*: m_atbashEncryption(message, key)*/
{
    // AtbashEncryption atbashEncryption(message, m_key);
    // m_atbashEncryption = &atbashEncryption;

    // m_atbashEncryption = new AtbashEncryption(message, m_key);
}

/*------------------------ Encryption related functions ----------------------*/

/*
* receives an input for encryption
*/
void Atbash::encrypt(const std::string *message)
{
    for (int i = 0; i < message->length(); i++) {
        for (int j = 0; j < alphabetLenght; j++) {
            if ( message->at(i) == this->alphabet.at(j)) {
                this->m_encryptedMessage += this->m_key.at(j);
            }
        }
    }
}

/*
* receives an input for encryption
*/
void Atbash::encrypt(const std::string *message, std::string key)
{
    setKey(key);
    encrypt(message);
}

/*
*
*/
const std::string Atbash::getEncryptedMessage()
{
    return this->m_encryptedMessage;
}

/*------------------------ Decryption related functions ----------------------*/

/*
* receives an input for decryption
*/
void Atbash::decrypt(const std::string *message)
{

}

/*
*
*/
const std::string Atbash::getDecryptedMessage()
{
    return "";
}

/*------------------------ xxxxxxxxxxxxxxxxxxxxxx ----------------------*/

/*
*
*/
void Atbash::setKey(std::string key)
{
    // std::cout << "atbash::setKey()::key: " << key << std::endl;
    this->m_key = key;
}

/*
*
*/
std::string Atbash::getKey()
{
    return this->m_key;
}

/*
*
*/
bool Atbash::validateInputMessage(std::string message)
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
bool Atbash::validateKey(std::string key)
{
    bool retVal = true;
    if(key.length() == alphabetLenght)
    {
        retVal = false;
    }
    /* add more conditions */
    return retVal;
}
