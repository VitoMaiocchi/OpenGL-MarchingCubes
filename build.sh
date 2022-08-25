g++ -c src/*.cpp
g++ -o app main.o  -L. libraries/lib/libglfw.so.3.3 -lGL
./app