//
// Created by Khanh Nguyen on 3/19/23.
//

#include "Cursor.h"

Cursor::Cursor()
{
    init();
}

void Cursor::eventHandler()
{
    sf::Time elapsedTime = clock.getElapsedTime();
    sf::Time elapsedTime2 = clock2.getElapsedTime();

    if(elapsedTime >= sf::milliseconds(500))
    {
        counter = counter % 2;
        cursor.setFillColor(colorSwitcher(counter));
        counter += 1;
        clock.restart();
    }
}

void Cursor::init()
{
    setUpCursor();
}

void Cursor::setUpCursor()
{
    cursor.setFillColor(sf::Color::Transparent);
    cursor.setCharacterSize(50);
    cursor.setPosition(0,0);
    cursor.setString("|");

    font.loadFromFile("AppleSDGothicNeo.ttc");
    cursor.setFont(font);
}

void Cursor::setSize(float size)
{
    cursor.setCharacterSize(size);
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(cursor);
}

sf::Color Cursor::colorSwitcher(int num)
{
    switch(counter)
    {
        case 0: return sf::Color::Black;
        case 1: return sf::Color::Transparent;
    }
    return sf::Color::Green; //default color
}

void Cursor::setPosition(sf::Vector2f position)
{
    cursor.setPosition(position);
}

void Cursor::setFont(sf::Font font)
{
    cursor.setFont(font);
}






