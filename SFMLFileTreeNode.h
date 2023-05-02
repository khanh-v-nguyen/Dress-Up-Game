//
// Created by Khanh Nguyen on 4/19/23.
//

#ifndef FILETREESOL_SFMLFILETREENODE_H
#define FILETREESOL_SFMLFILETREENODE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Images.h"

enum icon
{
    _FOLDER,
    _FILE
};

class SFMLFileTreeNode : public sf::Drawable
{
private:
    inline static sf::Texture texture;
    inline static sf::Font font;
    sf::Text data;
    sf::RectangleShape _icon;
    std::vector<SFMLFileTreeNode *> children;
    std::string getPath();
    void setUpIcon(icon i);
    void setUpData(std::string text);
    bool showChildren = false;
public:
    typedef std::vector<SFMLFileTreeNode*>::iterator iterator;
    iterator begin();
    iterator end();
    SFMLFileTreeNode();
    SFMLFileTreeNode(std::string text, icon i);
    void reposition() const;
    std::string getString();
    sf::FloatRect getGlobalBounds() const;
    void eventHandler(sf::RenderWindow & window, sf::Event event);
    void getPath(icon i);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void setPosition(sf::Vector2f pos);
    void push(std::string text, icon i);
    void push(SFMLFileTreeNode * node);
    std::string getData();
    void setString(std::string string);

};


#endif //FILETREESOL_SFMLFILETREENODE_H
