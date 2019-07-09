
g++ -std=c++11 -c lib/Animation.cpp -o target/Animation.o;
g++ -std=c++11 -c lib/AnimatedSprite.cpp -o target/AnimatedSprite.o;
g++ -std=c++11 -c entities/impls/Player.cpp -o target/Player.o;
g++ -std=c++11 -c core/main.cpp -o target/main.o;

# g++ Animation.o AnimatedSprite.o main.o Player.o -o mainp -lsfml-graphics -lsfml-window -lsfml-system;
# ./mainp;
# lib/AnimatedSprite.cpp core/main.cpp entities/impls/Player.cpp -o target/
