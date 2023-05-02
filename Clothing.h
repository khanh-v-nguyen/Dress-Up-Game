//
// Created by Khanh Nguyen on 4/20/23.
//

#ifndef MULTITEXT_CLOTHING_H
#define MULTITEXT_CLOTHING_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "Images.h"
#include "Character.h"
#include "CustomCursor.h"
class Clothing : public sf::Drawable
{
public:
    enum ItemType
    {
        SHIRTS,
        BOTTOMS,
        HAIR
    };

    Clothing(ImageItem num);
    Clothing(std::string path);
    Clothing(std::string path, ItemType type);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds();
    sf::Texture getTexture();
    ImageItem num;
    ImageItem getEnum();
    static sf::Vector2u getWindowSize(sf::RenderWindow window);
    std::string getPath();
    sf::Vector2f getPosition();

private:
    sf::Sprite clothing;
    std::string path;
    ItemType type;
    inline static sf::Texture texture;
    void setUpClothing(ImageItem num);
    void setCharacter();

};


#endif //MULTITEXT_CLOTHING_H
