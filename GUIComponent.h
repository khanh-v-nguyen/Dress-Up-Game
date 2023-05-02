//
// Created by Khanh Nguyen on 3/9/23.
//

#ifndef MULTITEXT_GUICOMPONENT_H
#define MULTITEXT_GUICOMPONENT_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "SnapshotInterface.h"

class GUIComponent : public EventHandler, public States, public SnapshotInterface, public sf::Drawable
{

};


#endif //MULTITEXT_GUICOMPONENT_H
