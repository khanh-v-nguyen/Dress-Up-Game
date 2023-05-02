//
// Created by Khanh Nguyen on 4/27/23.
//

#ifndef MULTITEXT_CLOSET_H
#define MULTITEXT_CLOSET_H

#include "SFML/Graphics.hpp"
#include <vector>
#include "Clothing.h"
#include "Position.h"
class Closet
{
public:


    Closet();
    std::vector<std::vector<Clothing>> closet;
    void pushback(std::string path, Clothing::ItemType type);
    std::vector<Clothing> operator[](int i) const;
    void reposition();
    void eventHandler(sf::RenderWindow & window, sf::Event event);
    void eventHandler(sf::RenderWindow & window, sf::Event event, Clothing::ItemType type);
    void setPosition(sf::Vector2f position);



private:
    void init();
    void setUpClothes();

};


#endif //MULTITEXT_CLOSET_H
