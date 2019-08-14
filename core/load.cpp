#include "./Namespaces/TextureManager.cpp"
#include "./Namespaces/ImageManager.cpp"

class Load {

    public:
    static void init(){
        textm::TextM::setFile(imageHandler::fireblast);
    }

};  