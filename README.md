# 42_cc01_get_next_line
42 cursus, common core, rank 01, project get_next_line

## Get_next_line
Get Next Line is a project at 42. `get_next_line(int fd)` function read from a file descriptor and print on the screen the result with the \n if there is any. The read function, from unistd.io library, read a certain amount of bytes from the passed file descriptor. These bytes are passed as BUFFER_SIZE at the compile time. The expected behaviour is that the function must read and return BUFFER_SIZE bytes until a \n or end of file (EOF), and must keep remaining bytes (if there is any) for a possible second call (or many other calls until EOF). This project deals with memory allocation and when to free and allocate memory to prevent leaks.

In this implementation you have a base function `int read_next_line(int fd, char **next_line)` designed to return an error code if was not possible to read a next line, avoiding a confusion between a null return and an error return of the original 'get_next_line' service.

## Compiling Get_next_line
cc -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c 

- The get_next_line.c has the main function.
- The get_next_line_utils.c has auxiliary functions.
- The get_next_line.h has the header with the prototypes of utils.
- main.c has the test.
- -D means that you want to define a macro named...
- BUFFER_SIZE macro determines how many bytes the read function will read from a file descriptor (if = 0 the return value will be null).

## Best gnl github Testers
- Francinette https://github.com/xicodomingues/francinette.git
- https://github.com/Tripouille/gnlTester.git

## Best gnl github alternatives
- https://github.com/gabrielasertori/Get-next-line
- https://github.com/Anasjaidi/get_next_line
- https://github.com/MarcFaussurier/get_next_linev2.git
- https://github.com/Rurikide/42.NEW_GET_NEXT_LINE.git
