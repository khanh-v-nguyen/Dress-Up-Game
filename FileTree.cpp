//
// Created by Khanh Nguyen on 4/11/23.
//

#include "FileTree.h"

FileTree::FileTree()
{

}

void FileTree::print()
{
    print(root);
    std::cout << std::endl;
}

void FileTree::push(std::string filePath) // filepath = folder1/folder2/file
{
    std::vector<std::string> paths = split(filePath);
    FileTreeNode * p = root;

    if(root == nullptr)
    {
        root = new FileTreeNode;
        //root -> children.push_back(createNode(paths[0]));
        root -> data = paths[0];
    }
    else if(p->data == paths[0])
    {
        for(int i = 1; i < paths.size() - 2; ++i)
        {
            if(p != nullptr)
                p = search(paths[i],p);
//            else
//            {
//                std::cout << "hi";
//                push("Folder1/Folder2");
//            }
        }
        p -> children.push_back(createNode(paths[paths.size()-1]));
        items.emplace_back(FileItem(p->children.back()->data));
        items.back().setPosition(100,100);
    }


}

std::vector<std::string> FileTree::split(std::string fileName)
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

void FileTree::push(FileTreeNode *node, std::string path)
{

}

FileTreeNode *FileTree::search(std::string s, FileTreeNode *node)
{
    auto iter = node -> children.begin();
    for(; iter != node -> children.end(); ++iter)
    {
        if((*iter)->data == s)
        {
            return *iter;
        }
    }
    return nullptr;
}

FileTreeNode *FileTree::createNode(std::string s)
{
    FileTreeNode * p = new FileTreeNode;
    p -> data = s;
    return p;
}

void FileTree::print(FileTreeNode *node)
{
    if(node != nullptr) //stopping case
    {
        std::cout << node->data << '/';
        auto iter = node->children.begin();
        for(; iter != node->children.end(); ++iter)
        {
            print(*iter);
        }
    }
}

void FileTree::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(FileItem i : items)
    {
        target.draw(i);
    }
}





