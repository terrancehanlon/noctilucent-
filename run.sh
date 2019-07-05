
g++ -std=c++11 -c Animation.cpp AnimatedSprite.cpp main.cpp Player.cpp;
g++ Animation.o AnimatedSprite.o main.o Player.o -o mainp -lsfml-graphics -lsfml-window -lsfml-system;

