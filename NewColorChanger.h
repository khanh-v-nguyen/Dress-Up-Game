//
// Created by Khanh Nguyen on 3/27/23.
//

#ifndef MULTITEXT_NEWCOLORCHANGER_H
#define MULTITEXT_NEWCOLORCHANGER_H
#include <vector>
#include <list>
#include "Letter.h"
#include "MultiText.h"
#include <string>
#include <iostream>
#include <map>

class NewColorChanger
{
public:
    NewColorChanger();
    NewColorChanger(MultiText &multiText);
    void iterateWord(std::list<Letter>::iterator start, std::list<Letter>::iterator end);

private:
    std::map<std::string, sf::Color> map;
    std::map<std::string, sf::Color> operatorMap;

    void colorWord(std::list<Letter>::iterator start, std::list<Letter>::iterator end, std::string string);
    sf::Color getColor(std::string string);
    void setUpMap();

};


#endif //MULTITEXT_NEWCOLORCHANGER_H
