//
// Created by Khanh Nguyen on 4/27/23.
//

#include "Closet.h"

Closet::Closet()
{
    init();
}

void Closet::pushback(std::string path, Clothing::ItemType type)
{
    closet[type].push_back(path);
}

void Closet::init()
{
    closet.emplace_back(); //shirts
    closet.emplace_back(); //bottoms
    closet.emplace_back(); //hair

    setUpClothes();
    reposition();
}

void Closet::setUpClothes()
{

    closet[Clothing::SHIRTS].push_back(Clothing("images/IMG_0206.PNG", Clothing::SHIRTS));
    closet[Clothing::SHIRTS].push_back(Clothing("images/IMG_0207.PNG", Clothing::SHIRTS));
    closet[Clothing::SHIRTS].push_back(Clothing("images/IMG_0208.PNG", Clothing::SHIRTS));
    closet[Clothing::SHIRTS].push_back(Clothing("images/IMG_0209.PNG", Clothing::SHIRTS));
    closet[Clothing::SHIRTS].push_back(Clothing("images/IMG_0233.PNG", Clothing::SHIRTS));
    closet[Clothing::SHIRTS].push_back(Clothing("images/IMG_0234.PNG", Clothing::SHIRTS));

    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0202.PNG", Clothing::BOTTOMS));
    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0203.PNG", Clothing::BOTTOMS));
    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0204.PNG", Clothing::BOTTOMS));
    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0205.PNG", Clothing::BOTTOMS));
    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0226.PNG", Clothing::BOTTOMS));
    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0227.PNG", Clothing::BOTTOMS));
    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0228.PNG", Clothing::BOTTOMS));
    closet[Clothing::BOTTOMS].push_back(Clothing("images/IMG_0230.PNG", Clothing::BOTTOMS));

    closet[Clothing::HAIR].push_back(Clothing("images/IMG_0210.PNG", Clothing::HAIR));
    closet[Clothing::HAIR].push_back(Clothing("images/IMG_0211.PNG", Clothing::HAIR));
    closet[Clothing::HAIR].push_back(Clothing("images/IMG_0212.PNG", Clothing::HAIR));
    closet[Clothing::HAIR].push_back(Clothing("images/IMG_0213.PNG", Clothing::HAIR));

//    closet[Clothing::SHIRTS][0].setPosition({1100,50});
//    closet[Clothing::BOTTOMS][0].setPosition({1100,50});
//    closet[Clothing::HAIR][0].setPosition({1100,50});
}

void Closet::reposition()
{

    for(int i = 0; i < closet.size(); ++i)
    {
        for(int j = 1; j < closet[i].size(); ++j)
        {
            closet[i][j].setPosition({closet[i][j-1].getPosition().x + 400, closet[i][j-1].getPosition().y});
            if(j % 2 == 0)
            {
                Position::bottom(closet[i][j-2], closet[i][j]);
            }
        }
    }
}

void Closet::setPosition(sf::Vector2f position)
{
    closet[Clothing::SHIRTS][0].setPosition({position});
    closet[Clothing::BOTTOMS][0].setPosition({position});
    closet[Clothing::HAIR][0].setPosition({position});

    reposition();
}

void Closet::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i = 0; i < closet.size(); ++i)
    {
        for(int j = 0; j<closet[i].size(); ++j)
        {
            closet[i][j].eventHandler(window, event);
        }
    }
}

void Closet::eventHandler(sf::RenderWindow &window, sf::Event event, Clothing::ItemType type)
{
    for(int j = 0; j<closet[type].size(); ++j)
    {
        closet[type][j].eventHandler(window, event);
    }
}

std::vector<Clothing> Closet::operator[](int i) const
{
    return closet[i];
}
