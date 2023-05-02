//
// Created by Khanh Nguyen on 4/12/23.
//

#ifndef FILETREESOL_FILEITEM_H
#define FILETREESOL_FILEITEM_H
#include <SFML/Graphics.hpp>
#include "Font.h"
#include <iostream>
class FileItem : public sf::Text
{
public:
    FileItem();
    FileItem(std::string s);
private:
    static sf::Font font;


};


#endif //FILETREESOL_FILEITEM_H
