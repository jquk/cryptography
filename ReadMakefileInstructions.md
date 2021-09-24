[Back to the main README.md](README.md)

# Editing the Makefile
## Define a macro in the Makefile
Example:
```
$ CFLAGS=-D VAR1 -D VAR2=*something*
```
If you are using default rules in the Makefile, this should work automatically. If you do not, and are invoking the C compiler explicitely, just make sure you are writing something along the lines of
```
$ $(CC) $(CFLAGS) -c -o $@ $<
```
Even more cute if the fact the CFLAGS=...above can be used on the command line rather than written in the Makefile (read man(1) manual page); this allows for easy reconfiguration of your compilation parameters at last moment, but the parameters won't be kept.

Best practices include using CPPFLAGS instead of CFLAGS, and using += instead of =; however support for these features are not as universal as the above, and depend on your make system.

Accordingly to cc manpage on linux and also POSIX specifies -D for the c99 command which is the standard name for the C compiler: pubs.opengroup.org/onlinepubs/9699919799/utilities/c99.html
```
-D name=definition
           The contents of definition are tokenized and processed as if they appeared during translation phase three in a #define directive.  In
           particular, the definition will be truncated by embedded newline characters.
```

**make vs cmake**
Make (or rather a Makefile) is a buildsystem - it drives the compiler and other build tools to build your code.

CMake is a generator of buildsystems. It can produce Makefiles, it can produce Ninja build files, it can produce KDEvelop or Xcode projects, it can produce Visual Studio solutions. From the same starting point, the same CMakeLists.txt file. So if you have a platform-independent project, CMake is a way to make it buildsystem-independent as well.

If you have Windows developers used to Visual Studio and Unix developers who swear by GNU Make, CMake is (one of) the way(s) to go.

I would always recommend using CMake (or another buildsystem generator, but CMake is my personal preference) if you intend your project to be multi-platform or widely usable. CMake itself also provides some nice features like dependency detection, library interface management, or integration with CTest, CDash and CPack.

Using a buildsystem generator makes your project more future-proof. Even if you're GNU-Make-only now, what if you later decide to expand to other platforms (be it Windows or something embedded), or just want to use an IDE?