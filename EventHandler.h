//
// Created by Khanh Nguyen on 3/9/23.
//

#ifndef MULTITEXT_EVENTHANDLER_H
#define MULTITEXT_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler
{
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};

#endif //MULTITEXT_EVENTHANDLER_H
