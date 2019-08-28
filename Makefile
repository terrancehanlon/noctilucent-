all:    
	g++ -std=c++11 -c -g lib/Animation.cpp -Ilib/Animation.hpp -o target/Animation.o;
	g++ -std=c++11 -c -g lib/AnimatedSprite.cpp -o target/AnimatedSprite.o;
	g++ -std=c++11 -c -g core/Namespaces/TextureManager.cpp -o target/TextureManagerNS.o
	g++ -std=c++11 -c -g core/Namespaces/ImageManager.cpp -o target/ImageManager.o
	g++ -std=c++11 -c -g core/Namespaces/AnimationHandler.cpp -o target/AnimationHandler.o
	g++ -std=c++11 -c -g entities/impls/Player.cpp -Ientities/headers/Player.hpp -o target/Player.o;
	g++ -std=c++11 -c -g entities/impls/Dummy.cpp -Ientities/headers/Dummy.hpp -o target/Dummy.o;
	g++ -std=c++11 -c -g entities/impls/HoodedOccult.cpp -Ientities/headers/HoodedOccult.hpp -o target/HoodedOccult.o
	g++ -std=c++11 -c -g core/levelManagement/levels/base/Level.cpp -o target/level.o;
	g++ -std=c++11 -c -g core/levelManagement/levels/base/LevelManager.cpp -Icore/levelManagement/levels/base/Level.hpp -o target/levelManager.o;
	g++ -std=c++11 -c -g core/levelManagement/levels/level1/levelOne.cpp -o target/levelOne.o;
	g++ -std=c++11 -c -g core/levelManagement/levels/level2/LevelTwo.cpp -o target/levelTwo.o;
	g++ -std=c++11 -c -g core/TextureManager.cpp -o target/texuremanager.o;
	g++ -std=c++11 -c -g core/UI/ActionBar.cpp -o target/ActionBar.o
	g++ -std=c++11 -c -g core/Abilities/Ability.cpp -o target/Ability.o
	g++ -std=c++11 -c -g core/Abilities/Range/FireBlast.cpp -o target/FireBlast.o
	g++ -std=c++11 -c -g core/main.cpp -o target/main.o;
	g++ target/Animation.o target/AnimatedSprite.o target/TextureManagerNS.o target/ImageManager.o target/AnimationHandler.o target/Player.o target/Dummy.o target/HoodedOccult.o target/main.o target/level.o target/levelManager.o target/levelOne.o target/levelTwo.o target/texuremanager.o target/ActionBar.o target/Ability.o target/FireBlast.o -o mainp -lcurl -lsfml-graphics -lsfml-window -lsfml-system;

main:
		g++ -std=c++11 -c core/main.cpp -o target/main.o;
		g++ target/Animation.o target/AnimatedSprite.o target/ImageManager.o target/Player.o target/Dummy.o target/main.o target/level.o target/levelManager.o target/levelOne.o target/levelTwo.o target/texuremanager.o -o mainp -lcurl -lsfml-graphics -lsfml-window -lsfml-system;
entity:
		g++ -std=c++11 -c entities/impls/Player.cpp -Ientities/headers/Player.hpp -o target/Player.o;
		g++ -std=c++11 -c entities/impls/Dummy.cpp -Ientities/headers/Dummy.hpp -o target/Dummy.o;
		g++ target/Animation.o target/AnimatedSprite.o target/Player.o target/Dummy.o target/main.o target/level.o target/levelManager.o target/levelOne.o target/levelTwo.o -o mainp -lsfml-graphics -lsfml-window -lsfml-system;
