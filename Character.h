//
// Created by Khanh Nguyen on 4/20/23.
//

#ifndef MULTITEXT_CHARACTER_H
#define MULTITEXT_CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Images.h"
#include "Position.h"
#include "States.h"
#include "MouseEvents.h"
class Character : public sf::Drawable, public States
{
public:
    Character();
    static void setName(std::string string);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    static void setClothesTexture();

    inline static sf::Font font;
    inline static sf::Text name;

    inline static sf::RectangleShape clothesBox;

    //void setTexture(std::string path, );
    inline static sf::Sprite shirtsBox;
    inline static sf::Sprite bottomsBox;
    inline static sf::Sprite hairBox;
    inline static sf::Sprite character;



private:

    inline static sf::RectangleShape box;
    inline static sf::Texture texture;
    inline static sf::Sprite dice;

    void setUpCharacter();
    void setUpTextureBoxes();
    void setUpPosition();

};


#endif //MULTITEXT_CHARACTER_H
