# allowed/forbidden in C++ Modules:

- Yes: Everything from the standard library (c++98).
- No: printf(), alloc(), free()
- No: ```using namespace <ns_name>```
- No: ```friend```
- No: Function implementations in header files (only templates)

# other requirements:

- no leaks (memory that has been allocated using ```new``` must be freed using ```delete```)
- C++02 until C++09 must use Orthodox Canonical Form
- No function
- It must be possible to use each header independently from others, so they have to include all the dependencies they need. Use include guards to avoid multiple inclusions
