//
// Created by Khanh Nguyen on 3/23/23.
//

#include "Word.h"

Word::Word() : Word("Default")
{

}

Word::Word(std::string string)
{
    this -> string = string;
    priority = 0;
    setUpString();
}

void Word::setWordPosition(sf::Vector2f position)
{
    this -> setPosition(position);
}

std::string Word::getString()
{
    return string;
}

std::string Word::getString() const
{
    return Text::getString();
}

sf::FloatRect Word::getGlobalBounds()
{
    return sf::Text::getGlobalBounds();
}

void Word::setUpString()
{
    font.loadFromFile("Roboto-Light.ttf");
    this -> setFont(font);
    this -> setString(string);
    this -> setFillColor(sf::Color::White);
    this ->setCharacterSize(25);
}

void Word::init()
{
    setUpString();
}

int Word::getPriority()
{
    return priority;
}

void Word::addPriority(int point)
{
    this -> priority += point;
}

bool operator>(const Word &lhs, const Word &rhs)
{
    return lhs.priority > rhs.priority;
}

bool operator<(const Word &lhs, const Word &rhs)
{
    return lhs.priority < rhs.priority;
}

bool operator==(const Word &lhs, const Word &rhs)
{
    return lhs.priority == rhs.priority;

}

bool operator!=(const Word &lhs, const Word &rhs)
{
    return lhs.priority != rhs.priority;
}


