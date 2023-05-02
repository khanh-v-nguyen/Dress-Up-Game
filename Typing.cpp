//
// Created by Khanh Nguyen on 2/22/23.
//

#include "Typing.h"

std::string Typing::textString = "";
sf::Font Typing::font;

Typing::Typing()
{

}

void Typing::init()
{
    setUpText();
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(sf::Event::TextEntered == event.type)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        {
            //textString.pop_back();
            list.pop_back();
        }
        else if(!KeyShortcuts::isUndo())
        {
            //textString += event.text.unicode;
            std::string temp;
            temp += static_cast<char>(event.text.unicode);
            list.push(temp);
        }
    }

    colorChanger.iterateWord(list.begin(), list.end());
}

void Typing::cursorEventHandler()
{
    Letter previous;
    cursor.eventHandler();
    if(!list.empty())
    {
        previous = list.back();
        cursor.setSize(previous.getCharacterSize());
        sf::Glyph glyph = previous.getFont().getGlyph(getString()[getString().size()-1], previous.getCharacterSize(), false);
        cursor.setPosition({previous.getPosition().x + glyph.advance, previous.getPosition().y});
    }
    else if(list.empty())
    {
        cursor.setPosition(initialLetterPosition);
    }
}

void Typing::update()
{
    text.setString(textString);
}

void Typing::setUpText()
{
    text.setCharacterSize(100);
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString(textString);
}

void Typing::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(list);
    target.draw(cursor);
}

std::string Typing::getString()
{
    return list.getString();
}

void Typing::setString(std::string string)
{
    list.setString(string);
    colorChanger.iterateWord(list.begin(), list.end()); // works but try to store colors instead maybe
}

Letter Typing::back()
{
    return list.back();
}

void Typing::setPosition(sf::Vector2f position)
{
    list.setPosition(position);
    initialLetterPosition = position;
}

bool Typing::empty()
{
    return list.empty();
}



