#include <iostream>
#include "message.h"

/*
*
*/
Message::Message() :
m_message( {"", 0, 0, 0, 0, { {'a', 0, 0.0f}, {'b', 0, 0.0f}, {'c', 0, 0.0f}, {'d', 0, 0.0f}, {'e', 0, 0.0f}, {'f', 0, 0.0f}, {'g', 0, 0.0f}, {'h', 0, 0.0f}, {'i', 0, 0.0f}, {'j', 0, 0.0f}, {'k', 0, 0.0f}, {'l', 0, 0.0f}, {'m', 0, 0.0f}, {'n', 0, 0.0f}, {'o', 0, 0.0f}, {'p', 0, 0.0f}, {'q', 0, 0.0f}, {'r', 0, 0.0f}, {'s', 0, 0.0f}, {'t', 0, 0.0f}, {'u', 0, 0.0f}, {'v', 0, 0.0f}, {'w', 0, 0.0f}, {'x', 0, 0.0f}, {'y', 0, 0.0f}, {'z', 0, 0.0f}, {'0', 0, 0.0f}, {'1', 0, 0.0f}, {'2', 0, 0.0f}, {'3', 0, 0.0f}, {'4', 0, 0.0f}, {'5', 0, 0.0f}, {'6', 0, 0.0f}, {'7', 0, 0.0f}, {'8', 0, 0.0f}, {'9', 0, 0.0f}, {' ', 0, 0.0f} } } )
{

}

/*
*
*/
Message::Message(const std::string *message) :
m_message( {"", 0, 0, 0, 0, { {'a', 0, 0.0f}, {'b', 0, 0.0f}, {'c', 0, 0.0f}, {'d', 0, 0.0f}, {'e', 0, 0.0f}, {'f', 0, 0.0f}, {'g', 0, 0.0f}, {'h', 0, 0.0f}, {'i', 0, 0.0f}, {'j', 0, 0.0f}, {'k', 0, 0.0f}, {'l', 0, 0.0f}, {'m', 0, 0.0f}, {'n', 0, 0.0f}, {'o', 0, 0.0f}, {'p', 0, 0.0f}, {'q', 0, 0.0f}, {'r', 0, 0.0f}, {'s', 0, 0.0f}, {'t', 0, 0.0f}, {'u', 0, 0.0f}, {'v', 0, 0.0f}, {'w', 0, 0.0f}, {'x', 0, 0.0f}, {'y', 0, 0.0f}, {'z', 0, 0.0f}, {'0', 0, 0.0f}, {'1', 0, 0.0f}, {'2', 0, 0.0f}, {'3', 0, 0.0f}, {'4', 0, 0.0f}, {'5', 0, 0.0f}, {'6', 0, 0.0f}, {'7', 0, 0.0f}, {'8', 0, 0.0f}, {'9', 0, 0.0f},  {' ', 0, 0.0f} } } )
{
    m_message.message = *message;
    getCharacterFrequencies(message, &m_message.charactersAndFrequencies);
    m_message.numberOfUniqueCharacters = getNumberOfUniqueCharacters();
}

/*---------------------------------------------------------------------------------------------*/

/*
*
*/
const uint8_t Message::getNumberOfUniqueCharacters()
{
    if ((m_message.numberOfUniqueCharacters == 0) && (m_message.message != "") )
    {
        // it has not been calculated, so must calculate it here
        for (size_t i = 0; i < sizeof(m_message.charactersAndFrequencies); i++)
        {
            if (m_message.charactersAndFrequencies[i].counter != 0)
            {
                m_message.numberOfUniqueCharacters++;
            }
        }
    }
    return m_message.numberOfUniqueCharacters;
}

/*
*
*/
// const std::string *Message::getUniqueCharacters()
// {
//     const std::string myString = std::string();
//     return &myString;
// }

/*
* returns the frequency of the given character
*/
const float Message::getMessage(const char myCharacter)
{
    return 0.01f;
}

/*
*
*/
void Message::getCharacterFrequencies(const std::string *message, latinAlphabetCharactersFrequencies_t *latinAlphabetCharactersFrequencies)
{
    for (size_t i = 0; i < message->length(); i++)
    {
        for (size_t j = 0; j < sizeof(m_message.charactersAndFrequencies); j++)
        {
            if(m_message.charactersAndFrequencies[j].character == message->at(i))
            {
                if (m_message.charactersAndFrequencies[j].counter == 0)
                {
                    m_message.numberOfUniqueCharacters++;
                }
                m_message.charactersAndFrequencies[j].counter++;
                m_message.charactersAndFrequencies[j].frequency = (m_message.charactersAndFrequencies[j].counter / (i+1));
                break;
            }
        }
        
    }
}


/*
*
*/
const message_t Message::getMessageMetadata()
{
    return m_message;
}
