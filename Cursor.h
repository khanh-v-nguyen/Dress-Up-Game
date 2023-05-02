//
// Created by Khanh Nguyen on 3/19/23.
//

#ifndef MULTITEXT_CURSOR_H
#define MULTITEXT_CURSOR_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Cursor : public sf::Text
{
public:
    Cursor();
    void eventHandler();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setPosition(sf::Vector2f position);
    void setFont(sf::Font font);
    void setSize(float size);


private:
    void init();
    void setUpCursor();
    sf::Color colorSwitcher(int num);
private:
    sf::Clock clock;
    sf::Clock clock2;

    sf::Text cursor;
    sf::Font font;
    int counter = 0;
};


#endif //MULTITEXT_CURSOR_H
