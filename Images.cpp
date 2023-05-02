//
// Created by Khanh Nguyen on 4/20/23.
//

#include "Images.h"
sf::Texture & Images::getImage(ImageItem num)
{
    std::string temp;
    switch(num)
    {
        case BACKGROUND:
        {
            temp = "testImages/background.jpg";
            break;
        }
        case BROWN_PINK_SHIRT:
        {
            temp="testImages/brownPinkShirt.png";
            break;
        }
        case BLUE_SKIRT:
        {
            temp="blueSkirt1.png";
            break;
        }
        case BLONDE_PIGTAILS:
        {
            temp="testImages/blondePigtails.png";
            break;
        }
        case WAND:
        {
            temp="images/wand.png";
            break;
        }
    }
    //texture.loadFromFile("testImages/" + num);
    //texture.loadFromFile(temp);

    sf::Texture * a = new sf::Texture();
    a->loadFromFile(temp);
    return *a;
}

sf::Texture &Images::getImage(std::string string)
{
//    string = "testImages/" + string;
    if(map.count(string) <= 0)
    {
        addTexture(string);
    }
    return map[string];
}

void Images::addTexture(std::string image)
{
    map[image] = sf::Texture();
    map[image].loadFromFile(image);
}

void Images::setWindowSize(sf::RenderWindow &window)
{
    windowSize = {static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)};
}

sf::Vector2f Images::getWindowSize()
{
    return windowSize;
}




