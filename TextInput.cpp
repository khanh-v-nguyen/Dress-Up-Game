//
// Created by Khanh Nguyen on 3/9/23.
//

#include "TextInput.h"

TextInput::TextInput()
{
    label.setString("Name");
    init();
}

void TextInput::init()
{
    positionAll();
    getSnapshot();
}

std::string TextInput::getText()
{
    return typing.getString();
}

Snapshot * TextInput::getSnapshot()
{
    TextInputSnapshot * p = new TextInputSnapshot;
    p->setString(string);
    History::push(this, p);
}

void TextInput::applySnapshot(Snapshot * snapshot)
{
    typing.setString(dynamic_cast<TextInputSnapshot*>(snapshot)->getString());
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    textbox.eventHandler(window);

    if(textbox.checkStates(HIGHLIGHTED) && event.type == sf::Event::TextEntered)
    {

        typing.addEventHandler(window, event);
        string = typing.getString();
        update(); //apply snapshot if command z clicked, if not then get a snapshot
        wordSort.setFile("testnames", typing.getString());
        wordSort.updateAutoCorrect();


    }
    sf::FloatRect t = textbox.getGlobalBounds();
    wordSort.setPosition({t.left, t.top + t.height});
}

void TextInput::loopingEventHandler()
{
    if(textbox.checkStates(HIGHLIGHTED))
    {
        typing.cursorEventHandler();
    }
}

void TextInput::update()
{
    if(KeyShortcuts::isUndo())
    {
        History::pop(); // will pop top AND call this function's applysnapshot in eventhandler (bc component -> snapshot in history)
    }
    else
    {
        getSnapshot();
    }
}

void TextInput::setUpWordSort()
{
   // wordSort.setFile("testnames");

}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(textbox);
    target.draw(typing);
    target.draw(label);
    target.draw(wordSort);
}

void TextInput::setLabel(std::string string)
{
    label.setString(string);
    positionAll();
}

void TextInput::setLabelSize(float size)
{
    label.setCharacterSize(size);
    positionAll();
}

void TextInput::setPosition(sf::Vector2f position)
{
    label.setPosition(position);
    positionAll();
}

void TextInput::positionAll()
{
    sf::FloatRect l = label.getGlobalBounds();
    sf::FloatRect b = textbox.getGlobalBounds();

    textbox.setPosition({l.left + l.width + 10, (l.top + l.height/2) - b.height /2});

    sf::FloatRect c = textbox.getGlobalBounds();

    typing.setPosition({c.left + 5,c.top + c.height/8});
}

sf::FloatRect TextInput::getGlobalBounds()
{
    return textbox.getGlobalBounds();
}

