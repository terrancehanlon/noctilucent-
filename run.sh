
g++ -std=c++11 -c lib/Animation.cpp -o target/Animation.o;
g++ -std=c++11 -c lib/AnimatedSprite.cpp -o target/AnimatedSprite.o;
g++ -std=c++11 -c entities/impls/Player.cpp -o target/Player.o;
g++ -std=c++11 -c core/levelManagement/levels/base/Level.cpp -o target/level.o;
g++ -std=c++11 -c core/levelManagement/levels/base/LevelManager.cpp -o target/levelManager.o;
g++ -std=c++11 -c core/levelManagement/levels/level1/LevelOne.cpp -o target/levelOne.o;
g++ -std=c++11 -c core/main.cpp -o target/main.o;

# g++ target/Animation.o target/AnimatedSprite.o target/Player.o target/main.o target/level.o target/levelManager.o target/levelOne.o -o mainp -lsfml-graphics -lsfml-window -lsfml-system;
# ./mainp;
# lib/AnimatedSprite.cpp core/main.cpp entities/impls/Player.cpp -o target/
