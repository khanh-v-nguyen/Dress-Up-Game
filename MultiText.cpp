//
// Created by Khanh Nguyen on 3/1/23.
//

#include "MultiText.h"

sf::Vector2f MultiText::initialPosition;

MultiText::MultiText()
{

}

void MultiText::push(Letter letter)
{
    list.push_back(letter);
    setPosition({0,0});
}

void MultiText::push(std::string string)
{
    list.emplace_back(string);
    setPosition(initialPosition); // setting the position of the first element in the list(starting point for multitext)
}

void MultiText::setPosition(sf::Vector2f initialPos)
{
    this -> initialPosition = initialPos;

    for(int i = 0; i < list.size(); i++)
    {
        if(i == 0)
        {
            it = list.begin();

            list.front().setPosition(initialPosition);
        }
        else
        {
            Letter previous = *(it);

            sf::Glyph glyph = it->getFont().getGlyph(previous.getString()[0], previous.getCharacterSize(), false);

            (++it) -> setPosition(previous.getPosition().x + glyph.advance, previous.getPosition().y);
        }
    }
}

std::list<Letter>::iterator MultiText::begin()
{
//    Letter a = list.front();
//    std::cout << a.getString();
    return list.begin();
}

std::list<Letter>::iterator MultiText::end()
{
    return list.end();
}

void MultiText::pop_back()
{
    if(!list.empty())
    {
        list.pop_back();
    }
}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) //the one i made
{
    if(!list.empty())
    {
        for(auto iter = list.begin(); iter != list.end(); iter++)
        {
            target.draw(*iter);
        }
    }
}

void MultiText::setString(std::string string)
{
    while(!list.empty())
    {
        list.pop_back();
    }

    for(int i = 0; i < string.size(); i++)
    {
        std::string temp = string;
        temp = string[i];
        push(temp);
    }
}

std::string MultiText::getString()
{
    std::string temp;
    for(auto iter = list.begin(); iter != list.end(); iter++)
    {
        temp += iter->getString();
    }
    return temp;
}

std::string MultiText::getString(std::list<Letter>::iterator begin, std::list<Letter>::iterator end)
{
    std::string temp;
    for(auto iter = begin; iter != end; iter++)
    {
        temp += iter->getString();
    }
    return temp;
}

Letter MultiText::back()
{
    return list.back();
}

Letter MultiText::front()
{
    return list.front();
}

bool MultiText::empty()
{
    return list.empty();
}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const //the one from sf::drawable
{
    if(!list.empty())
    {
        for(auto iter = list.begin(); iter != list.end(); iter++)
        {
            target.draw(*iter);
        }
    }
}