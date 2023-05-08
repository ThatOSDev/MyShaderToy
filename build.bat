gcc.exe -Wall -std=c17 -m64 -O2 -Ilibs\glfw-3.3.8.bin.WIN64\include -Ilibs\glad\include -c libs\glad\src\gl.c -o gl.o
gcc.exe -Wall -std=c17 -m64 -O2 -Ilibs\glfw-3.3.8.bin.WIN64\include -Ilibs\glad\include -c main.c -o main.o
gcc.exe -Llibs\glfw-3.3.8.bin.WIN64\lib-mingw-w64 -o MyShaderToy.exe gl.o main.o  -static -m64 -lglfw3 -lgdi32 -s -mwindows

del *.o

pause
