MAKEFILE_DEFINED_MACROS = -D CAESAR=1 -D ATBASH=2
CIPHER_COMPILATION_TARGET = ''

define compile
$(eval target := $(strip $(1)))
@echo executing the compile function, the target parameter is $(target)
@echo $(MAKEFILE_DEFINED_MACROS)
rm -rf build/$(target)
g++ main.cpp cipher/$(target)/$(target).cpp -o build/$(target) $(MAKEFILE_DEFINED_MACROS)
./build/$(target)
endef

all:
	@echo executing the target all

main:
	@echo executing the target all

caesar:
	@echo executing the target $@
	rm -rf build/$(target)
	$(eval MAKEFILE_DEFINED_MACROS+=-D CIPHER_COMPILATION_TARGET=CAESAR)
	$(call compile,$@)

atbash:
	@echo executing the target $@
	rm -rf build/$(target)
	$(eval MAKEFILE_DEFINED_MACROS+=-D CIPHER_COMPILATION_TARGET=ATBASH)
	$(call compile,$@)


# caesar atbash: main

########################3
show_compiler:
ifeq ($(CC),gcc)
	@echo "gcc compiler"
else
	@echo "other compiler"
endif

clean:
	rm -rf bin/*
	rm -rf build/*

debug:
    $(info SOURCES: $(MAKEFILE_DEFINED_MACROS))