all:    
	g++ -std=c++11 -c lib/Animation.cpp -Ilib/Animation.hpp -o target/Animation.o;
	g++ -std=c++11 -c lib/AnimatedSprite.cpp -o target/AnimatedSprite.o;
	g++ -std=c++11 -c entities/impls/Player.cpp -Ientities/headers/Player.hpp -o target/Player.o;
	g++ -std=c++11 -c core/levelManagement/levels/base/Level.cpp -o target/level.o;
	g++ -std=c++11 -c core/levelManagement/levels/base/LevelManager.cpp -Icore/levelManagement/levels/base/Level.hpp -o target/levelManager.o;
	g++ -std=c++11 -c core/levelManagement/levels/level1/levelOne.cpp -o target/levelOne.o;
	g++ -std=c++11 -c core/main.cpp -o target/main.o;
	g++ target/Animation.o target/AnimatedSprite.o target/Player.o target/main.o target/level.o target/levelManager.o target/levelOne.o -o mainp -lsfml-graphics -lsfml-window -lsfml-system;

