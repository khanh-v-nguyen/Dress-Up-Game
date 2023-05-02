//
// Created by Khanh Nguyen on 4/20/23.
//

#ifndef MULTITEXT_CUSTOMCURSOR_H
#define MULTITEXT_CUSTOMCURSOR_H
#include "SFML/Graphics.hpp"
#include "MouseEvents.h"
#include "Images.h"
#include "Character.h"

class CustomCursor : public sf::Drawable
{
public:
    CustomCursor();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    inline static bool clothesPlaced = false;

private:
    sf::Texture texture;
    sf::Texture texture2;
    sf::Sprite hand;

    inline static std::string path;
    inline static sf::Sprite tempClothes;
    inline static sf::Texture tempClothesTexture;
};


#endif //MULTITEXT_CUSTOMCURSOR_H
