//
// Created by Khanh Nguyen on 4/20/23.
//

#include "Character.h"

Character::Character()
{
    setUpCharacter();
}

void Character::setName(std::string string)
{
    name.setString(string);
    Position::centerTop(character, name);
}

void Character::setUpPosition()
{

}

void Character::setUpCharacter()
{
    texture.loadFromFile("images/base0.png");
    character.setTexture(texture);
    sf::FloatRect c = character.getGlobalBounds();

    name.setPosition(c.left + c.width - 35, c.top + c.height / 8);
    name.setString("Khanh");
    font.loadFromFile("CHERI___.TTF");
    name.setFont(font);
    name.setFillColor(sf::Color::White);

    box.setSize({700,1200});
    //box.setFillColor({234, 221, 202});
    box.setTexture(&Images::getImage("images/image3.png"));

    box.setPosition(400, 100);
    Position::center(box, character);
    Position::centerTop(character, name);

    setUpTextureBoxes();

    dice.setTexture(Images::getImage("images/dice.png"));
    sf::FloatRect b = box.getGlobalBounds();
    sf::FloatRect d = dice.getGlobalBounds();
    dice.setPosition({b.left + b.width - d.width, b.top + b.height-d.height});
}

void Character::setUpTextureBoxes()
{
    hairBox.setPosition(character.getPosition());
    sf::FloatRect c = character.getGlobalBounds();
    shirtsBox.setPosition(c.left , c.top + (c.height / 3.3));
    bottomsBox.setPosition(c.left, c.top + (c.height/2));
}

void Character::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    int random = rand() % 3;
    std::string temp = "images/image3.png";

    switch(random)
    {
        case 1: temp = "images/image7.png"; break;
        case 2: temp = "images/image6.png"; break;
    }

    if(MouseEvents::isClicked(dice, window))
    {
        box.setTexture(&Images::getImage(temp));
    }
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(box);
    target.draw(character);
    target.draw(bottomsBox);
    target.draw(shirtsBox);
    target.draw(hairBox);
    target.draw(dice);
    target.draw(name);

}

