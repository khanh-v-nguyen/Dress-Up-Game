//
// Created by Khanh Nguyen on 4/20/23.
//

#ifndef MULTITEXT_SAVECIRCLE_H
#define MULTITEXT_SAVECIRCLE_H
#include "Circle.h"
#include <string>
#include <fstream>
class SaveCircle
{
public:
    static void save(Circle &circle, std::string filepath);
    static void load(Circle &circle, std::string filepath);
};

#endif //MULTITEXT_SAVECIRCLE_H
