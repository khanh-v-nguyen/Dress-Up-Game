//
// Created by Khanh Nguyen on 3/19/23.
//

#ifndef MULTITEXT_POSITION_H
#define MULTITEXT_POSITION_H

#include <SFML/Graphics.hpp>

class Position
{
public:
    template <class T>
    static void top(T& obj1, T& obj2);

    template <class T>
    static void bottom(T& obj1, T& obj2);

    template <class T, class S>
    static void bottom(T& obj1, S& obj2);

    template <class T>
    static void left(T& obj1, T& obj2);

    template <class T>
    static void right(T& obj1, T& obj2);

    template <class T>
    static void center(T& obj1, T& obj2);

    template <class T>
    static void centerBottom(T& obj1, T& obj2);

    template <class T, class S>
    static void center(T& obj1, S& obj2);

    template <class T, class S>
    static void centerTop(T& obj1, S& obj2);

    template <class T, class S>
    static void centerBottom(T& obj1, S& obj2);

};

#include "Position.cpp"



#endif //MULTITEXT_POSITION_H
