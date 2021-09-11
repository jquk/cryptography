MAKEFILE_DEFINED_MACROS = -D CAESAR=1 -D ATBASH=2

target=''

main:
# DO all the work in here
	echo $(MAKEFILE_DEFINED_MACROS) \
	rm -rf bin/$(target) && \
	g++ main.cpp cipher/$(target)/$(target).cpp -o bin/$(target) $(MAKEFILE_DEFINED_MACROS) && \
	./bin/$(target)

caesar: MAKEFILE_DEFINED_MACROS+=-D CIPHER_COMPILATION_TARGET=CAESAR
	target=caesar

atbash: MAKEFILE_DEFINED_MACROS+=-D CIPHER_COMPILATION_TARGET=ATBASH
	target=atbash

caesar atbash: main

show_compiler:
ifeq ($(CC),gcc)
	echo "gcc compiler"
else
	echo "other compiler"
endif

clean:
	rm -rf bin/*
	rm -rf build/*

debug:
    $(info SOURCES: $(MAKEFILE_DEFINED_MACROS))