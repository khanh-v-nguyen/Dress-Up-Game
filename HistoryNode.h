//
// Created by Khanh Nguyen on 3/16/23.
//

#ifndef MULTITEXT_HISTORYNODE_H
#define MULTITEXT_HISTORYNODE_H
#include "GUIComponent.h"
#include "Snapshot.h"

struct HistoryNode
{
    GUIComponent * component;
    Snapshot * snapshot;
};

#endif //MULTITEXT_HISTORYNODE_H
