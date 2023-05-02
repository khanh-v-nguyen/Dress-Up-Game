//
// Created by Khanh Nguyen on 4/19/23.
//

#include "SFMLFileTree.h"

SFMLFileTree::SFMLFileTree()
{

}


void SFMLFileTree::print()
{
    //print(root);
    std::cout << std::endl;
}

void SFMLFileTree::push(std::string filePath) // filepath = folder1/folder2/file
{
    std::vector<std::string> paths = split(filePath);
    SFMLFileTreeNode * p = root;

    if(root == nullptr)
    {
        root = new SFMLFileTreeNode(paths[0], _FOLDER);
        //root -> children.push_back(createNode(paths[0]));
        //root -> data = paths[0];
    }
    else if(p->getString() == paths[0])
    {
        for(int i = 1; i < paths.size() - 1; ++i)
        {
            if(p != nullptr)
                p = search(paths[i],p);
        }
       p->push(paths[paths.size()-1], _FILE);
    }
}

void SFMLFileTree::setPosition(sf::Vector2f position)
{
    root->setPosition(position);
}

std::vector<std::string> SFMLFileTree::split(std::string fileName)
{
    std::stringstream sstr(fileName);
    std::vector<std::string> v;

    while(sstr.good())
    {   std::string substr;
        getline(sstr, substr, '/');
        v.push_back(substr);
    }
    return v;
}

void SFMLFileTree::push(SFMLFileTreeNode *node, std::string path)
{

}


SFMLFileTreeNode *SFMLFileTree::search(std::string s, SFMLFileTreeNode *node)
{
    auto iter = node -> begin();
    for(; iter != node -> end(); ++iter)
    {
        if((*iter)->getData() == s)
        {
            return *iter;
        }
    }
    return nullptr;
}

SFMLFileTreeNode *SFMLFileTree::createNode(std::string s)
{
    SFMLFileTreeNode * p = new SFMLFileTreeNode;
    p -> setString(s);
    return p;
}

//void FileTree::print(SFMLFileTreeNode *node)
//{
//    if(node != nullptr) //stopping case
//    {
//        std::cout << node->data << '/';
//        auto iter = node->children.begin();
//        for(; iter != node->children.end(); ++iter)
//        {
//            print(*iter);
//        }
//    }
//}

void SFMLFileTree::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*root);
}


//void FileTree::draw(sf::RenderTarget &target, sf::RenderStates states) const
//{
//    target.draw(*root);
////    for(FileItem i : items)
////    {
////        target.draw(i);
////    }
//}

void SFMLFileTree::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    root->eventHandler(window, event);
}
