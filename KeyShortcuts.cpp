//
// Created by Khanh Nguyen on 3/9/23.
//

#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        return true;
    }
    return false;
}
