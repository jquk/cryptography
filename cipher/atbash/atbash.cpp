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
Atbash::Atbash(int key) /*: m_atbashEncryption(key)*/
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
Atbash::Atbash(const std::string *message, int key) /*: m_atbashEncryption(message, key)*/
{
    // AtbashEncryption atbashEncryption(message, m_key);
    // m_atbashEncryption = &atbashEncryption;

    // m_atbashEncryption = new AtbashEncryption(message, m_key);
}

/*------------------------ Encryption related functions ----------------------*/

/*
*
*/
bool Atbash::validateInput()
{
    bool retVal = false;
    if (m_inputMessage != "") {
        retVal = true;
    }
    return retVal;
}

/*
* receives an input for encryption
*/
void Atbash::encrypt(const std::string *message)
{
    for (int i = 0; i < message->length(); i++) {
        for (int j = 0; j < alphabetLenght; j++) {
            if ( message->at(i) == this->alphabet[j]) {
                if (j < (alphabetLenght - this->m_key)) {
                    this->m_encryptedMessage += alphabet[j + this->m_key];
                } else {
                    this->m_encryptedMessage += alphabet[0 + this->m_key];// <-- WRONG
                }
            }
        }
    }
    // this->m_encryptedMessage = "hahaha";
}

/*
* receives an input for encryption
*/
void Atbash::encrypt(const std::string *message, int key)
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
void Atbash::setKey(int key)
{
    // std::cout << "atbash::setKey()::key: " << key << std::endl;
    this->m_key = key;
}

/*
*
*/
int Atbash::getKey()
{
    return this->m_key;
}
