//
// Created by Khanh Nguyen on 2/22/23.
//

#ifndef MULTITEXT_TYPING_H
#define MULTITEXT_TYPING_H
#include <SFML/Graphics.hpp>
#include "MultiText.h"
#include "KeyShortcuts.h"
#include <iostream>
#include "Position.h"
#include "Cursor.h"
#include "NewColorChanger.h"

class Typing : public sf::Drawable
{
public:
    Typing();
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    std::string getString();
    void setString(std::string string);
    Letter back();
    void cursorEventHandler();
    void setPosition(sf::Vector2f position);
    bool empty();

private:
    sf::Vector2f initialLetterPosition;
    NewColorChanger colorChanger;
    sf::Text text;
    static std::string textString;
    static sf::Font font;
    void setUpText();
    void init();
    MultiText list;
    Cursor cursor;

};


#endif //MULTITEXT_TYPING_H
