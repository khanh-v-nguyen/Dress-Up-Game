//
// Created by Khanh Nguyen on 4/20/23.
//

#ifndef MULTITEXT_IMAGES_H
#define MULTITEXT_IMAGES_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
enum ImageItem
{
    BACKGROUND,
    BROWN_PINK_SHIRT,
    BLUE_SKIRT,
    BLONDE_PIGTAILS,
    WAND
};
class Images
{
public:
    inline static sf::Texture texture;
    static sf::Texture & getImage(ImageItem num);
    static void addTexture(std::string image);
    inline static std::map<std::string, sf::Texture> map;
    static sf::Texture & getImage(std::string string);

    static void setWindowSize(sf::RenderWindow &window);
    static sf::Vector2f getWindowSize();
    inline static sf::Vector2f windowSize;
    inline static bool shirtPlaced = false;
    inline static bool hairPlaced = false;
    inline static bool bottomsPlaced = false;


};


#endif //MULTITEXT_IMAGES_H
