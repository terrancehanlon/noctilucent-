#include <SFML/Graphics.hpp>
#include <string>

namespace textm {

    extern sf::Texture fireblastTexture;

    class TextM {

        public:
            static sf::Texture fbText;
            static void setFile(std::string path){
                fbText.loadFromFile(path);
            };

            static sf::Texture gettext(){
                return fbText;
            };

    };


};