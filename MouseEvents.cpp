//
// Created by Khanh Nguyen on 3/17/23.
//

#ifndef MULTITEXT_MOUSEEVENTS_CPP
#define MULTITEXT_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
bool MouseEvents::isHovered(const T& Obj, const sf::RenderWindow& window)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return Obj.getGlobalBounds().contains(mpos);
}

template<class T>
bool MouseEvents::isClicked( T& Obj,  sf::RenderWindow& window)
{
    return isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents::isHovered( T& Obj,  sf::RenderWindow& window)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return Obj.getGlobalBounds().contains(mpos);
}

template<class T>
bool MouseEvents::isClicked(const T& Obj, const sf::RenderWindow& window)
{
    return isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents::isNotClicked(const T& Obj, const sf::RenderWindow& window)
{
    return !isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}


#endif