//
// Created by Khanh Nguyen on 4/20/23.
//
#include "SaveCircle.h"

void SaveCircle::save(Circle &circle, std::string filepath)
{
    std::ofstream out;
    out.open(filepath);
    out << circle.getPosition().x << std::endl;
    out << circle.getPosition().y << std::endl;
    out.close();
    std::cout << "save";

}

void SaveCircle::load(Circle &circle, std::string filepath)
{
    std::cout << "load";
    std::ifstream fin;
    fin.open(filepath);
    if(fin.fail())
    {
        throw "could not find file";
    }
    float x;
    float y;
    fin >> x;
    fin >> y;


    circle.setPosition({x,y});
    std::cout << circle.getPosition().x << std::endl;
    std::cout << circle.getPosition().y << std::endl;

    fin.close();
}
