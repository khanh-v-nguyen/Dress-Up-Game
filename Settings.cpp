//
// Created by Khanh Nguyen on 4/30/23.
//

#include "Settings.h"

Settings::Settings()
{
    init();
}

void Settings::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    menu.eventHandler(window, event);

    if(MouseEvents::isClicked(menu[0], window))
    {
        enableStates(ENABLED);
        menu[0].enableStates(ENABLED);
        menu[1].disableStates(ENABLED);

    }
    if(MouseEvents::isClicked(menu[1], window))
    {
        enableStates(ENABLED);
        menu[1].enableStates(ENABLED);
        menu[0].disableStates(ENABLED);

    }

    if(menu[0].checkStates(ENABLED))
    {
        textInput.addEventHandler(window, event);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || MouseEvents::isClicked(confirm, window))
        {
            confirmText.setFillColor({255, 87, 51, 100});
            Character::setName(textInput.getText());
        }
        else
        {
            confirmText.setFillColor({255, 87, 51, 255});
        }
    }

    if(menu[1].checkStates(ENABLED))
    {
        tree.eventHandler(window, event);
    }


    if(MouseEvents::isClicked(closeBox, window))
    {
        disableStates(ENABLED);
    }
}

void Settings::loopingEventHandler(sf::RenderWindow &window, sf::Event event)
{
    textInput.loopingEventHandler();
}

void Settings::init()
{
    setMenuItems();
    textInput.setPosition({1200,600});
    setUpBox();
    setUpTree();
}

void Settings::setMenuItems()
{
    menu.push_back("Name Change");
    menu.push_back("Load Outfit");

}

void Settings::setUpTree()
{
    tree.push("Folder1");
    tree.push("Folder1/Spring");
    tree.push("Folder1/Spring/Outfit 1");
    tree.push("Folder1/Casual");
    tree.push("Folder1/Party");
    tree.setPosition({200, 400});
}

void Settings::setMenuTexture()
{

}

void Settings::setUpBox()
{
    box.setPosition(Images::windowSize.x /2, Images::windowSize.y /2);
    box.setSize({800,800});
    box.setPosition({0,100});
    box.setTexture(&Images::getImage("images/imagePink1.png"));

    closeBox.setTexture(Images::getImage("images/closeButton.png"));
    confirm.setSize({300, 100});
    confirm.setTexture(&Images::getImage("images/imagePink1.png"));

    Position::bottom(textInput, confirm);

    sf::FloatRect b = box.getGlobalBounds();
    closeBox.setPosition(b.left, b.top);

    Position::center(box, textInput);

    confirmText.setString("Confirm");
    confirmFont.loadFromFile("CHERI___.TTF");
    confirmText.setFont(confirmFont);
    confirmText.setCharacterSize(40);
    confirmText.setFillColor({255, 87, 51});

    Position::centerBottom(textInput, confirm);
    Position::center(confirm, confirmText);


}

void Settings::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(menu);

    if(checkStates(ENABLED))
    {
        target.draw(box);
        target.draw(closeBox);
        if(menu[0].checkStates(ENABLED))
        {
            target.draw(textInput);
            target.draw(confirm);
            target.draw(confirmText);
        }
        if(menu[1].checkStates(ENABLED))
        {
            target.draw(tree);
        }
    }





}




