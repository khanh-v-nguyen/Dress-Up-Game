//
// Created by Khanh Nguyen on 4/20/23.
//

#include "CustomCursor.h"

CustomCursor::CustomCursor()
{

}

void CustomCursor::eventHandler(sf::RenderWindow &window, sf::Event event)
{

//    if(MouseEvents::isClicked(hand, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
//    {
//        hand.setTexture(Images::getImage(WAND));
//    }
//    else
//    {
//        hand.setTexture(Images::getImage("images/mickey2.png"));
//
//    }

    hand.setPosition((sf::Vector2f) sf::Mouse::getPosition(window));
    hand.setTexture(Images::getImage("images/mickey2.png"));
}


void CustomCursor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(hand);
}
