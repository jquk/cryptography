#include <string.h>
/*
typedef struct {
    float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, m0, m1, m2, m3, m4, m5, m6, m7, m8, m9;
} latinAlphabetCharactersFrequencies;
*/

typedef struct {
    char character;
    int counter;
    float frequency;
}characterAndFrequency_t;

typedef characterAndFrequency_t latinAlphabetCharactersFrequencies_t[256];

typedef struct {
    std::string message;
    uint64_t numberOfCharacters;
    uint8_t numberOfUniqueCharacters;
    uint8_t numberOfLeters;
    uint8_t numberOfNumbers;
    characterAndFrequency_t charactersAndFrequencies[256];
}message_t;