//
// Created by Khanh Nguyen on 4/19/23.
//

#ifndef FILETREESOL_SFMLFILETREE_H
#define FILETREESOL_SFMLFILETREE_H

#include <iostream>
#include <sstream>
#include "FileTree.h"
#include "FileTreeNode.h"
#include "FileItem.h"
#include "SFMLFileTreeNode.h"
class SFMLFileTree : public sf::Drawable
{
private:
    SFMLFileTreeNode * root = nullptr;
    std::vector<std::string> split(std::string fileName);
    void print(SFMLFileTreeNode * node);
    void push(SFMLFileTreeNode * node, std::string path);
    SFMLFileTreeNode * search(std::string s, SFMLFileTreeNode * node);
    SFMLFileTreeNode * createNode(std::string s);
    std::vector<FileItem> items;

public:
    SFMLFileTree();
    void print();
    void push(std::string filePath);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow & window, sf::Event event);
    void setPosition(sf::Vector2f position);

};


#endif //FILETREESOL_SFMLFILETREE_H
