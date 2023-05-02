//
// Created by Khanh Nguyen on 4/19/23.
//

#include "SFMLFileTreeNode.h"

std::string SFMLFileTreeNode::getPath()
{

}

void SFMLFileTreeNode::setUpIcon(icon i)
{
    if(i == _FILE)
    {
        //_icon.setFillColor(sf::Color::Red);
        _icon.setTexture(&Images::getImage("images/file.png"));
    }
    else
    {
        //_icon.setFillColor(sf::Color::Blue);
        _icon.setTexture(&Images::getImage("images/folder.png"));

    }
    _icon.setSize({80,80});

}

SFMLFileTreeNode::SFMLFileTreeNode() : SFMLFileTreeNode("test", _FOLDER)
{

}

SFMLFileTreeNode::SFMLFileTreeNode(std::string text, icon i)
{
    setUpIcon(i);
    setUpData(text);
    setPosition({100,100});
}

void SFMLFileTreeNode::reposition() const
{
    if(showChildren)
    {
        sf::Vector2f pos = _icon.getPosition();
        pos.x += 25;
        pos.y = _icon.getGlobalBounds().top + _icon.getGlobalBounds().height;
        for(SFMLFileTreeNode * c : children)
        {
            c->setPosition(pos);
            pos.y += c->getGlobalBounds().height;
        }
    }
}

sf::FloatRect SFMLFileTreeNode::getGlobalBounds() const
{
    sf::FloatRect b = _icon.getGlobalBounds();
    if(showChildren)
    {
        for(SFMLFileTreeNode * child : children)
        {
            b.height += child->getGlobalBounds().height;
        }
    }
    return b;
}

void SFMLFileTreeNode::setPosition(sf::Vector2f pos)
{
    _icon.setPosition(pos);
    data.setPosition({pos.x + _icon.getGlobalBounds().width + 10, pos.y});
    reposition();
}

void SFMLFileTreeNode::setUpData(std::string text)
{
    font.loadFromFile("OpenSans-Bold.ttf");
    data.setFont(font);
    data.setCharacterSize(60);
    data.setString(text);
    data.setFillColor(sf::Color::White);
}

void SFMLFileTreeNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    reposition();
    window.draw(_icon);
    window.draw(data);
    if(showChildren)
    {
        auto iter = children.cbegin();
        for(const SFMLFileTreeNode * child : children)
        {
            child->draw(window,states); // for all children, call this function (draw every child in that this node has)
        }
    }

}

std::string SFMLFileTreeNode::getString()
{
    return data.getString();
}

void SFMLFileTreeNode::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(_icon.getGlobalBounds().contains(mpos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        showChildren = !showChildren;
        //reposition();
        Character::shirtsBox.setTexture(Images::getImage("images/IMG_0208.PNG"));
        Character::bottomsBox.setTexture(Images::getImage("images/IMG_0205.PNG"));
        Character::hairBox.setTexture(Images::getImage("images/IMG_0212.PNG"));
    }
    if(showChildren)
    {
        for(SFMLFileTreeNode * c : children)
            c->eventHandler(window, event);
    }

}

void SFMLFileTreeNode::setString(std::string string)
{
    data.setString(string);

}

typename SFMLFileTreeNode::iterator SFMLFileTreeNode::begin()
{
    return children.begin();
}

typename SFMLFileTreeNode::iterator SFMLFileTreeNode::end()
{
    return children.end();
}

void SFMLFileTreeNode::push(std::string text, icon i)
{
    SFMLFileTreeNode * node = new SFMLFileTreeNode(text, i);
    push(node);
}

void SFMLFileTreeNode::push(SFMLFileTreeNode *node)
{
    children.push_back(node);
}

std::string SFMLFileTreeNode::getData()
{
    return data.getString();
}
