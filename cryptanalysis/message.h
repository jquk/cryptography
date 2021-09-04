#include <string>
#include "message_cfg.h"

class Message {
public:
    // initialize
    Message();
    Message(const std::string *message);
    ~Message() {};

    // main functions
    const message_t getMessageMetadata();
    const uint8_t getNumberOfUniqueCharacters();
    const std::string *getUniqueCharacters();
    const float getMessage(const char myCharacter);// returns the frequency of the given character
    void getCharacterFrequencies(const std::string *message, latinAlphabetCharactersFrequencies_t *latinAlphabetCharactersFrequencies);// returns the frequency of the characters in the message

protected:
    // uint8_t m_numberOfUniqueCharacters;// = 0;
    // latinAlphabetCharactersFrequencies_t m_latinAlphabetCharactersFrequencies = {latinAlphabetCharactersFrequencies_cfg};
    // latinAlphabetCharactersFrequencies_t m_latinAlphabetCharactersFrequencies;// = { {'a', 0, 0.0f}, {'b', 0, 0.0f}, {'c', 0, 0.0f}, {'d', 0, 0.0f}, {'e', 0, 0.0f}, {'f', 0, 0.0f}, {'g', 0, 0.0f}, {'h', 0, 0.0f}, {'i', 0, 0.0f}, {'j', 0, 0.0f}, {'k', 0, 0.0f}, {'l', 0, 0.0f}, {'m', 0, 0.0f}, {'n', 0, 0.0f}, {'o', 0, 0.0f}, {'p', 0, 0.0f}, {'q', 0, 0.0f}, {'r', 0, 0.0f}, {'s', 0, 0.0f}, {'t', 0, 0.0f}, {'u', 0, 0.0f}, {'v', 0, 0.0f}, {'w', 0, 0.0f}, {'x', 0, 0.0f}, {'y', 0, 0.0f}, {'z', 0, 0.0f}, {'0', 0, 0.0f}, {'1', 0, 0.0f}, {'2', 0, 0.0f}, {'3', 0, 0.0f}, {'4', 0, 0.0f}, {'5', 0, 0.0f}, {'6', 0, 0.0f}, {'7', 0, 0.0f}, {'8', 0, 0.0f}, {'9', 0, 0.0f} };
    message_t m_message;
};
