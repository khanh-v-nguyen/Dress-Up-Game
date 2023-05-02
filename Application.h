//
// Created by Khanh Nguyen on 2/22/23.
//

#ifndef MULTITEXT_APPLICATION_H
#define MULTITEXT_APPLICATION_H

#include "Typing.h"
#include <SFMl/Graphics.hpp>
#include <iostream>
#include "Textbox.h"
#include "TextInput.h"
#include "Cursor.h"
#include "ColorChanger.h"
#include "Word.h"
#include "FileReader.h"
#include "WordSort.h"
#include "SFMLFileTree.h"
#include "Clothing.h"
#include "DropDownMenu.h"
#include "Circle.h"
#include "SaveCircle.h"
#include "Character.h"
#include "CustomCursor.h"
#include "Menu.h"

class Application
{
public:
    Application();
    Application(sf::VideoMode, std::string title);
    void run();

private:
    sf::RenderWindow window;
    void eventHandler();
    void runLoop();


};


#endif //MULTITEXT_APPLICATION_H
