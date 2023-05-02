//
// Created by Khanh Nguyen on 3/23/23.
//

#include "DropDownMenu.h"

DropDownMenu::DropDownMenu()
{
    init();
}

void DropDownMenu::init()
{
    inputBox.setText("Menu");
    setUpPosition();
    getSnapshot();
    inputBox.enableStates(ITEMS_HIDDEN);
    this -> enableStates(NAME_CHANGEABLE);
}

void DropDownMenu::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    menuItems.eventHandler(window, event);
    inputBox.eventHandler(window, event);

    for(Item & i : menuItems) // if broken check iterators in itemlist
    {
        if(i.checkStates(SELECTED))
        {
            if(checkStates(NAME_CHANGEABLE))
            {
                inputBox.setText(i.getText());
            }

            inputBox.enableStates(ITEMS_HIDDEN);

            if(MouseEvents::isClicked(i.getBox(), window) && inputBox.checkStates(ITEMS_HIDDEN))
            {
                getSnapshot();
            }
        }
    }

//    if(MouseEvents::isClicked(inputBox.getBox(), window))
//    {
//        inputBox.setColor(sf::Color::Blue);
//    }

    if(event.type == sf::Event::KeyPressed)
    {
        update(); //popping history stack and applying this function's applysnapshot()
    }

}

void DropDownMenu::setPosition(sf::Vector2f position)
{
    inputBox.setPosition(position);
    setUpPosition();
}

void DropDownMenu::setSize(sf::Vector2f size)
{
    inputBox.setSize(size);
    menuItems.setSize(size);
    sf::FloatRect i = inputBox.getGlobalBounds();
    menuItems.setPosition({i.left,i.top + i.height});

}

void DropDownMenu::setUpPosition()
{
    sf::FloatRect i = inputBox.getGlobalBounds();
    menuItems.setPosition({i.left,i.top + i.height});
}

void DropDownMenu::push_back(std::string title)
{
    menuItems.addItem(title);
    setUpPosition();
}

void DropDownMenu::pop_back()
{

}

sf::FloatRect DropDownMenu::getGlobalBounds()
{
    return inputBox.getGlobalBounds();
}

void DropDownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(inputBox);
    if(!inputBox.checkStates(ITEMS_HIDDEN))
    {
        target.draw(menuItems);
    }
}

Snapshot *DropDownMenu::getSnapshot()
{
    auto * p = new DropDownSnapshot;
    p ->setString(inputBox.getTitle());
    History::push(this, p);
    return p;
}

void DropDownMenu::applySnapshot(Snapshot *snapshot)
{
    DropDownSnapshot * p = dynamic_cast<DropDownSnapshot * >(snapshot);
    inputBox.setText(p -> getString());
}


void DropDownMenu::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        History::pop();
    }
}

void DropDownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

Item &DropDownMenu::operator[](int i)
{
    return menuItems[i];
}

const Item &DropDownMenu::operator[](int i) const
{
    return menuItems[i];
}

void DropDownMenu::setTexture()
{

}

bool DropDownMenu::isClicked(sf::RenderWindow &window, sf::Event event)
{
    if(inputBox.isClicked(window, event))
    {
        return true;
    }
    return false;
}

std::vector<Item>::iterator DropDownMenu::begin()
{
    return menuItems.begin();
}

std::vector<Item>::iterator DropDownMenu::end()
{
    return menuItems.end();
}

int DropDownMenu::size()
{
    return menuItems.size();
}
