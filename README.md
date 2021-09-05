# cryptography
Cryptography training

# Ciphers

1. [Atbash](cipher/atbash/README.md)

# Compile And Run
## Compile and run with cmake
Note that at the moment there is a single target.
```
$ mkdir -p build && cd build
$ cmake ..
$ cmake --build .
```
Alternativelly, from the root project directory, run this:
```
$ cmake -H. -Bbuild
```

## Compile and run manually
1. Compile and run the atbash algorithm:
```
$ rm -rf bin/atbash reset && g++ cipher/atbash/main.cpp cipher/atbash/atbash.cpp -o bin/atbash && ./bin/atbash
```
**Compile and run the cryptanalysis tools:**
```
$ rm -rf cryptanalysis/bin/cryptanalysis && reset && g++ cryptanalysis/main.cpp cryptanalysis/message.cpp -o cryptanalysis/bin/cryptanalysis && ./cryptanalysis/bin/cryptanalysis
```

# Cryptanalysis
