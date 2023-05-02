//
// Created by Khanh Nguyen on 3/17/23.
//

#include "Textbox.h"

Textbox::Textbox() : Textbox({500,100})
{
}

Textbox::Textbox(sf::Vector2f size)
{
    this -> size = size;
    init();
}

void Textbox::setPosition(sf::Vector2f position)
{
    box.setPosition(position);
}

void Textbox::init()
{
    setUpBox();
}

void Textbox::setUpBox()
{
    box.setSize(size);
    box.setFillColor(sf::Color::White);
    box.setOutlineThickness(5);
    box.setOutlineColor(defaultColor);
}

void Textbox::eventHandler(sf::RenderWindow &window)
{
    if(MouseEvents::isClicked(box,window))
    {
        box.setOutlineColor(sf::Color(227, 115, 131));
        this -> enableStates(HIGHLIGHTED);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !MouseEvents::isHovered(box,window))
    {
        box.setOutlineColor(defaultColor);
        this -> disableStates(HIGHLIGHTED);
    }
}

void Textbox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(box);
}

sf::FloatRect Textbox::getGlobalBounds()
{
    return box.getGlobalBounds();
}


