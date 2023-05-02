//
// Created by Khanh Nguyen on 3/20/23.
//

#ifndef MULTITEXT_COLORCHANGER_H
#define MULTITEXT_COLORCHANGER_H

#include "MultiText.h"
#include <SFML/Graphics.hpp>
#include <map>

class ColorChanger
{
public:
    ColorChanger();
    void changeColor(MultiText &text);
    void print(std::string::iterator start, std::string::iterator end);

private:
    void colorString(std::list<Letter>::iterator start, std::list<Letter>::iterator end);
    sf::Color getColor(std::string word);
    std::map<std::string, sf::Color> keywordMap;
    std::map<std::string, sf::Color> operatorMap;

    void setUpMap();
    std::string keywords[4];
    std::string operators[4];

};


#endif //MULTITEXT_COLORCHANGER_H
