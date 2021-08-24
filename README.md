# cryptography
Cryptography training

# Ciphers

## 01 Atbash
**Introduction**

The Atbash cipher is a substitution cipher with a specific key where the letters of the alphabet are reversed. I.e. all 'A's are replaced with 'Z's, all 'B's are replaced with 'Y's, and so on. It was originally used for the Hebrew alphabet, but can be used for any alphabet.

The Atbash cipher offers almost no security, and can be broken very easily. Even if an adversary doesn't know a piece of ciphertext has been enciphered with the Atbash cipher, they can still break it by assuming it is a substitution cipher and determining the key using hill-climbing. The Atbash cipher is also an Affine cipher with a=25 and b = 25, so breaking it as an affine cipher also works.

**The Algorithm**

The Atbash cipher is essentially a substitution cipher with a fixed key, if you know the cipher is Atbash, then no additional information is needed to decrypt the message.
The substitution key is:
```
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ZYXWVUTSRQPONMLKJIHGFEDCBA
```
To encipher a message, find the letter you wish to encipher in the top row, then replace it with the letter in the bottom row. In the example below, we encipher the message 'ATTACK AT DAWN'. The first letter we wish to encipher is 'A', which is above 'Z', so the first ciphertext letter is 'Z'. The next letter is 'T', which is above 'G', so that comes next. The whole message is enciphered:
```
ATTACK AT DAWN
ZGGZXP ZG WZDM
```
To decipher a message, the exact same procedure is followed. Find 'Z' in the top row, which is 'A' in the bottom row. Continue until the whole message is deciphered.

**Compile and run**
```
$ reset && g++ cipher/atbash/main.cpp cipher/atbash/atbash.cpp -o bin/atbash && ./bin/atbash
```
# Cryptanalysis
