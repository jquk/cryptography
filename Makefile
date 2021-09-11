MAKEFILE_MACROS = -D CAESAR=1 -D ATBASH=2 -D CIPHER_COMPILATION_TARGET=ATBASH

atbash:
	rm -rf bin/atbash && \
	reset && \
	g++ main.cpp cipher/atbash/atbash.cpp -o bin/atbash $(MAKEFILE_MACROS) && \
	./bin/atbash