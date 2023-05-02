//
// Created by Khanh Nguyen on 3/17/23.
//

#ifndef MULTITEXT_TEXTBOX_H
#define MULTITEXT_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "MouseEvents.h"

class Textbox : public States, public sf::RectangleShape
{
public:
    Textbox();
    Textbox(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void eventHandler(sf::RenderWindow &window);
    sf::FloatRect getGlobalBounds();
private:
    sf::RectangleShape box;
    void init();
    void setUpBox();
    sf::Vector2f size;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Color defaultColor = sf::Color::Black;


};


#endif //MULTITEXT_TEXTBOX_H
