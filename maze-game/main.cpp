#include "game.h"
#include "SFML/Audio.hpp"


int main(void) {

    Music music;

    music.openFromFile("music/backMusic.wav");
    //music.setVolume(50);
    music.play();
    music.setLoop(true);

    mazeGame game;
    //game.Intro();
    //game.GameSet();
    
    game.GameStart();
    
    return 0;
}