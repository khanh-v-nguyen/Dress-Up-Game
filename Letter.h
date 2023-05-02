//
// Created by Khanh Nguyen on 3/1/23.
//

#ifndef MULTITEXT_LETTER_H
#define MULTITEXT_LETTER_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Letter : public sf::Text
{
public:
    Letter();
    Letter(char a);
    Letter(std::string string);
    Letter(sf::Text text);
    std::string getString();
    sf::Font getFont();
    sf::Text text;
private:
    sf::Font Font;
    std::string string;
};


#endif //MULTITEXT_LETTER_H
