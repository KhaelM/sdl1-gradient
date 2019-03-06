gcc -c function.c `sdl-config --cflags`
gcc -c main.c `sdl-config --cflags`
gcc -o window main.o function.o `sdl-config --libs`