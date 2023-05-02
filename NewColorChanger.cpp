//
// Created by Khanh Nguyen on 3/27/23.
//

#include "NewColorChanger.h"

NewColorChanger::NewColorChanger()
{

}

NewColorChanger::NewColorChanger(MultiText &multiText)
{

}

void NewColorChanger::iterateWord(std::list<Letter>::iterator start, std::list<Letter>::iterator end)
{
    std::list<Letter>::iterator it;
    auto s = start;
    auto e = start;

//    for(it = start; it != end; ++it)
//    {
//        it->setFillColor(sf::Color::Magenta);
//    }

    std::string string;
    for(; e != end; ++e)
    {
        string += (e->getString());
        if(e->getString() == " ")
        {
            colorWord(s, e, string);
            s = e;
            ++s;
            string = "";
        }
    }
}

void NewColorChanger::colorWord(std::list<Letter>::iterator start, std::list<Letter>::iterator end, std::string string)
{
    for(auto it = start; it != end; ++it)
    {
        it ->setFillColor(getColor(string));
    }
}

sf::Color NewColorChanger::getColor(std::string string)
{
    setUpMap();
    string.pop_back(); // removing the space
    std::cout << string;

//    if(string == "char")
//    {
//        return sf::Color::Blue;
//    }

    if(map.count(string) != 0)
    {
        return map.at(string);
    }
    else if(operatorMap.count(string) != 0)
    {
        return operatorMap.at(string);
    }
    else if(isdigit(string[0]))
    {
        return sf::Color::Red;
    }

    return sf::Color::Black;
}

void NewColorChanger::setUpMap()
{
    map.emplace("char", sf::Color::Blue);
    map.emplace("int", sf::Color::Blue);
    map.emplace("double", sf::Color::Blue);
    map.emplace("float", sf::Color::Blue);

    operatorMap.emplace("+", sf::Color::Green);
    operatorMap.emplace("-", sf::Color::Green);
    operatorMap.emplace("*", sf::Color::Green);
    operatorMap.emplace("/", sf::Color::Green);
}
