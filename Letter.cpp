//
// Created by Khanh Nguyen on 3/1/23.
//

#include "Letter.h"

Letter::Letter()
{
//    this ->setString("Default");
//
//    Font.loadFromFile("CHERI___.TTF");
//
//    this -> setFont(Font);
//
//    this ->setCharacterSize(30);
//
//    this -> setPosition(100,100);
}

Letter::Letter(std::string string)
{
    this -> string = string;

    this -> setString(string);

    //Font.loadFromFile("Roboto-Light.ttf");
    Font.loadFromFile("CHERI___.TTF");


    this -> setFont(Font);

    this ->setCharacterSize(60);

    this ->setColor(sf::Color::Black);

    //this -> setPosition(100,100);

}

Letter::Letter(char a)
{
    this -> setString(a);

    //Font.loadFromFile("Roboto-Light.ttf");
    Font.loadFromFile("CHERI___.TTF");


    this -> setFont(Font);

    this ->setCharacterSize(60);

}

std::string Letter::getString()
{
    return string;
}

sf::Font Letter::getFont()
{
    return Font;
}

Letter::Letter(sf::Text text)
{
    *this = text;
}




