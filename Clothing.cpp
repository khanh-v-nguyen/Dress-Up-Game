//
// Created by Khanh Nguyen on 4/20/23.
//

#include "Clothing.h"

Clothing::Clothing(ImageItem num)
{
    setUpClothing(num);
    this->num = num;
}

Clothing::Clothing(std::string path)
{
    this -> path = path;
    clothing.setTexture(Images::getImage(path));
}

Clothing::Clothing(std::string path, Clothing::ItemType type)
{
    this -> path = path;
    this -> type = type;
    clothing.setTexture(Images::getImage(path));
}

sf::Vector2f Clothing::getPosition()
{
    return clothing.getPosition();
}

ImageItem Clothing::getEnum()
{
    return num;
}

std::string Clothing::getPath()
{
    return "TEST";
}

void Clothing::setUpClothing(ImageItem num)
{
    clothing.setTexture(Images::getImage(num));
}

void Clothing::setPosition(sf::Vector2f position)
{
    clothing.setPosition(position);
}

sf::FloatRect Clothing::getGlobalBounds()
{
    return clothing.getGlobalBounds();
}

sf::Texture Clothing::getTexture()
{
    sf::Texture temp;
    temp = *clothing.getTexture();
    return temp;
}

void Clothing::eventHandler(sf::RenderWindow & window, sf::Event event)
{
    if(MouseEvents::isClicked(clothing, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
        //clothing.setPosition(mpos.x - c.width/2, mpos.y - c.height/2);
        setCharacter();

    }
}

void Clothing::setCharacter()
{
    switch(type)
    {
        case 0: Character::shirtsBox.setTexture(Images::getImage(path)); break;
        case 1: Character::bottomsBox.setTexture(Images::getImage(path)); break;
        case 2: Character::hairBox.setTexture(Images::getImage(path)); break;

    }
}


void Clothing::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(clothing);
}

sf::Vector2u Clothing::getWindowSize(sf::RenderWindow window)
{
    return window.getSize();
}
