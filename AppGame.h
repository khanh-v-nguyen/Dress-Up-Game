//
// Created by Khanh Nguyen on 4/23/23.
//

#ifndef MULTITEXT_APPGAME_H
#define MULTITEXT_APPGAME_H
#include <SFML/Graphics.hpp>
#include "Images.h"
#include "CustomCursor.h"
#include "Clothing.h"
#include "Character.h"
#include "DropDownMenu.h"
#include "OptionsBar.h"
#include "Settings.h"
class AppGame
{
public:
    AppGame();
    AppGame(sf::VideoMode, std::string title);
    void run();
private:
    sf::RenderWindow window;
    void eventHandler();
    void runLoop();
    sf::RectangleShape background;
    Character character;
    Settings settings;
};


#endif //MULTITEXT_APPGAME_H
