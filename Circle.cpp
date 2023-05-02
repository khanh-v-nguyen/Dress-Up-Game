//
// Created by Khanh Nguyen on 4/20/23.
//

#include "Circle.h"

Circle::Circle()
{
    circle.setRadius(50);
}

void Circle::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(circle.getGlobalBounds().contains(mpos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        circle.setPosition(mpos);
    }
}

sf::Vector2f Circle::getPosition() const
{
    return circle.getPosition();
}

void Circle::setPosition(sf::Vector2f pos)
{
    circle.setPosition(pos);
}

void Circle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(circle);
}
