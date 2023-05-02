//
// Created by Khanh Nguyen on 3/20/23.
//

#include "ColorChanger.h"

ColorChanger::ColorChanger()
{
    //setUpMap();
}

void ColorChanger::print(std::string::iterator start, std::string::iterator end)
{
    for(; start != end; ++start)
        std::cout << *start;
    std::cout << std::endl;
}

void ColorChanger::changeColor(MultiText &text)
{
    std::string input = text.getString();
    std::string s;

    auto start = input.begin();
    auto end = s.begin();
    auto it = text.begin();
    auto iter = text.begin();

    for (; end != input.end(); ++end)
    {
        if (*end == ' ')
        {
            //print(start, end);
            colorString(it, iter);
            //std::cout << it->getString();
            //std::cout << iter->getString();

            start = end;
            it = iter;
            ++start;
            ++it;
        }
        ++iter;
    }
}

void ColorChanger::colorString(std::list<Letter>::iterator start, std::list<Letter>::iterator end)
{
    for(auto it = start; it != end; ++it)
    {
        it->setFillColor(getColor(it->getString()));
    }

}

sf::Color ColorChanger::getColor(std::string word)
{
    if(word == "khanh")
    {
        return sf::Color::Magenta;
    }
    return sf::Color::Red;

//    if(keywordMap.find(word) != keywordMap.end())
//    {
//        return sf::Color::Blue;
//    }
//    else if(operatorMap.find(word) != operatorMap.end())
//    {
//        return sf::Color::Green;
//    }
//    else if(isdigit(word[0]))
//    {
//        return sf::Color::Red;
//    }
}



void ColorChanger::setUpMap()
{
    keywordMap = {{"int", sf::Color::Blue},{"double", sf::Color::Blue},{"float", sf::Color::Blue},{"char", sf::Color::Blue}};
    operatorMap = {{"+", sf::Color::Blue},{"-", sf::Color::Blue},{"*", sf::Color::Blue},{"-", sf::Color::Blue}};
}



