# Cryptography
This project's goal is to practice cryptography techniques, starting from the oldest ciphers until the modern techniques available in the public domain.

# Ciphers
0. [Caesar](cipher/caesar/README.md)
1. [Atbash](cipher/atbash/README.md)
2. Others to come.

# Compile And Run
## Compile and run with cmake
Note that at the moment there is a single target.
```
$ mkdir -p build && cd build
$ cmake ..
$ cmake --build .
$ cd ..
```
Alternativelly, all in one go, like this:
```
$ mkdir -p build && cd build && cmake .. && cmake --build . --target <target-name> && cd ..
```
Alternativelly, from the root project directory, run this:
```
$ cmake -H. -Bbuild
```

## Compile and run manually
1. Compile and run the atbash algorithm:
```
$ rm -rf bin/atbash && reset && g++ main.cpp cipher/atbash/atbash.cpp -o bin/atbash && ./bin/atbash
```
**Compile and run the cryptanalysis tools:**
```
$ rm -rf cryptanalysis/bin/cryptanalysis && reset && g++ cryptanalysis/main.cpp cryptanalysis/message.cpp -o cryptanalysis/bin/cryptanalysis && ./cryptanalysis/bin/cryptanalysis
```

# Cryptanalysis
See the subdirectory named 'cryptoanalysis', for analysis tools, e.g. char frequency for profiling encrypted messages.

# Makefile reference
[ReadMakefileInstructions.md](ReadMakefileInstructions.md)
