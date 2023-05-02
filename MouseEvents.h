//
// Created by Khanh Nguyen on 3/17/23.
//

#ifndef MULTITEXT_MOUSEEVENTS_H
#define MULTITEXT_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>
class MouseEvents
{
public:
    template<class T>
    static bool isHovered(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isHovered( T& Obj,  sf::RenderWindow& window);

    template<class T>
    static bool isClicked( T& Obj,  sf::RenderWindow& window);

    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow& window);

};

#include "MouseEvents.cpp"
#endif //MULTITEXT_MOUSEEVENTS_H
