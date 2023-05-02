//
// Created by Khanh Nguyen on 4/24/23.
//

#ifndef MULTITEXT_OPTIONSBAR_H
#define MULTITEXT_OPTIONSBAR_H
#include "DropDownMenu.h"
#include <vector>
#include "Clothing.h"
#include <map>
#include "States.h"
#include "Closet.h"
#include "Position.h"
#include "Character.h"
#include "SFMLFileTree.h"

class OptionsBar : public sf::Drawable, States
{
public:

    OptionsBar();
    void eventHandler(sf::RenderWindow & window, sf::Event event);
    void loopingEventHandler(sf::RenderWindow & window, sf::Event event);


private:
    void setUpMenu();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    DropDownMenu optionBar;

    std::map<std::string, std::vector<Clothing>> map; // dropdownmenu item name, map of all clothes that are that tag

    sf::RectangleShape panelBox;

    Closet closet;
    Clothing::ItemType state = Clothing::SHIRTS;

    Character character;

    SFMLFileTree fileTree;

    Item & operator[](int i);
    const Item & operator[](int i) const;


};


#endif //MULTITEXT_OPTIONSBAR_H
