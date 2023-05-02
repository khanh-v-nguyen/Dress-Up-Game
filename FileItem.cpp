//
// Created by Khanh Nguyen on 4/12/23.
//

#include "FileItem.h"

sf::Font FileItem::font;

FileItem::FileItem()
{

}

FileItem::FileItem(std::string s)
{
    this -> setString(s);
    font.loadFromFile("OpenSans-Bold.ttf");
    this -> setFont(font);
}
