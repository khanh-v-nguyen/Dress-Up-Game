//
// Created by Khanh Nguyen on 4/11/23.
//

#ifndef FILETREESOL_FILETREENODE_H
#define FILETREESOL_FILETREENODE_H
#include <string>
#include <vector>

struct FileTreeNode
{
    std::string data;
    std::vector<FileTreeNode *> children;
};


#endif //FILETREESOL_FILETREENODE_H
