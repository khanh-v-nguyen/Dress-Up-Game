//
// Created by Khanh Nguyen on 4/24/23.
//

#include "OptionsBar.h"

OptionsBar::OptionsBar()
{
    setUpMenu();
}

void OptionsBar::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    optionBar.eventHandler(window, event);
    character.eventHandler(window,event);


    for(int i = 0; i < optionBar.size(); ++i)
    {
        if(MouseEvents::isClicked(optionBar[i], window))
        {
            state = static_cast<Clothing::ItemType>(i);
        }
    }

    closet.eventHandler(window, event, state);
}

void OptionsBar::loopingEventHandler(sf::RenderWindow &window, sf::Event event)
{

}


void OptionsBar::setUpMenu()
{
    panelBox.setSize({1000,1200});
    panelBox.setPosition({Images::windowSize.x /2 , 100});
    //panelBox.setFillColor({238, 220, 130, 220});

    optionBar.push_back("Shirts");
    optionBar.push_back("Bottoms");
    optionBar.push_back("Hair");

    sf::FloatRect p = panelBox.getGlobalBounds();
    sf::FloatRect o = optionBar.getGlobalBounds();
    optionBar.setPosition({p.left + p.width - o.width, optionBar.getGlobalBounds().height});

    sf::FloatRect o1 = optionBar.getGlobalBounds();
    closet.setPosition({p.left, o1.top + o1.height});
    panelBox.setTexture(&Images::getImage("images/image.png"));
}

void OptionsBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(panelBox);
    target.draw(character);

    for(int i = 0; i < closet[state].size(); ++i)
    {
        target.draw(closet[state][i]);
    }

    target.draw(optionBar);
}

Item &OptionsBar::operator[](int i)
{
    return optionBar[i];
}

const Item &OptionsBar::operator[](int i) const
{
    return optionBar[i];
}
