#include <iostream>
#include <engine3d-audio/Sound.hpp>
using namespace std;




int main(int argc, char** argv){
    engine3d::audio::Sound sound = engine3d::audio::Sound(argv[1]);
    while(true){
        sound.OnPlay();
        
        char ch;
        std::cin >> ch;
        if(ch == 'q'){
            sound.OnStop();
            break;
        }
    }
    return 0;
}
