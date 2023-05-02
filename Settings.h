//
// Created by Khanh Nguyen on 4/30/23.
//

#ifndef MULTITEXT_SETTINGS_H
#define MULTITEXT_SETTINGS_H
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "TextInput.h"
#include "Character.h"
#include "SFMLFileTree.h"

class Settings : public sf::Drawable, States
{
public:
    Settings();
    void eventHandler(sf::RenderWindow & window, sf::Event event);
    void loopingEventHandler(sf::RenderWindow & window, sf::Event event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    Menu menu;
    TextInput textInput;
    sf::RectangleShape box;
    sf::Sprite closeBox;
    sf::RectangleShape confirm;
    sf::Text confirmText;
    sf::Font confirmFont;
    SFMLFileTree tree;

    void init();
    void setMenuItems();
    void setMenuTexture();
    void setUpBox();
    void setUpTree();
};


#endif //MULTITEXT_SETTINGS_H
