//
// Created by Khanh Nguyen on 4/11/23.
//

#ifndef FILETREESOL_FILETREE_H
#define FILETREESOL_FILETREE_H
#include <iostream>
#include <sstream>
#include "FileTree.h"
#include "FileTreeNode.h"
#include "FileItem.h"
class FileTree : public sf::Drawable
{
private:
    FileTreeNode * root = nullptr;
    std::vector<std::string> split(std::string fileName);
    void print(FileTreeNode * node);
    void push(FileTreeNode * node, std::string path);
    FileTreeNode * search(std::string s, FileTreeNode * node);
    FileTreeNode * createNode(std::string s);

    std::vector<FileItem> items;

public:
    FileTree();
    void print();
    void push(std::string filePath);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //FILETREESOL_FILETREE_H
