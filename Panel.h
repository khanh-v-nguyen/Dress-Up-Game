//
// Created by Khanh Nguyen on 4/27/23.
//

#ifndef MULTITEXT_PANEL_H
#define MULTITEXT_PANEL_H
#include <SFML/Graphics.hpp>

class Panel
{
    enum PanelType
    {
        SHIRTS,
        BOTTOMS,
        HAIR
    };
    Panel();
    Panel(PanelType);

};


#endif //MULTITEXT_PANEL_H
