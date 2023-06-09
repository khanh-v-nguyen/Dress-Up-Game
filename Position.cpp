//
// Created by Khanh Nguyen on 3/19/23.
//
#ifndef MULTITEXT_POSITION_CPP
#define MULTITEXT_POSITION_CPP

#include "Position.h"

template<class T>
void Position::top(T &obj1, T &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left, o1.top - o1.height});
}

template<class T>
void Position::bottom(T &obj1, T &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left, o1.top + o1.height});
}

template<class T, class S>
void Position::bottom(T &obj1, S &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left, o1.top + o1.height});
}

template<class T>
void Position::right(T &obj1, T &obj2)
{

}

template<class T>
void Position::left(T &obj1, T &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left + o1.width, o1.top});
}

template<class T>
void Position::center(T &obj1, T &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left + o1.width/2 - o2.width /2, o1.top + o1.height/2 - o2.height/2});
}

template<class T, class S>
void Position::center(T &obj1, S &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left + o1.width/2 - o2.width /2, o1.top + o1.height/2 - o2.height/2});
}

template<class T, class S>
void Position::centerTop(T &obj1, S &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left + o1.width/2 - o2.width /2, o1.top - o2.height});
}


template<class T, class S>
void Position::centerBottom(T &obj1, S &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left + o1.width/2 - o2.width /2, o1.top + o1.height});
}

template<class T>
void Position::centerBottom(T &obj1, T &obj2)
{
    sf::FloatRect o1 = obj1.getGlobalBounds();
    sf::FloatRect o2 = obj2.getGlobalBounds();

    obj2.setPosition({o1.left + o1.width/2 - o2.width /2, o1.top + o1.height});
}

#endif
