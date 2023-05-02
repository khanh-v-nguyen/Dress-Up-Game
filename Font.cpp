//
// Created by Khanh Nguyen on 4/12/23.
//

#include "Font.h"

sf::Font Font::font;

sf::Font Font::getFont()
{
    font.loadFromFile("OpenSans-Bold.ttf");
    return font;
}
