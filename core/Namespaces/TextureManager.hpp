#ifndef TEXTM_INCLUDE
#define TEXTM_INCLUDE


namespace textm {

     sf::Texture fireblastTexture;
     static sf::Texture fbText;

    class TextM {

        public:
            static void setFile(std::string path){
                fbText.loadFromFile(path);
            };

            static sf::Texture gettext(){
                return fbText;
            };

    };


};


#endif