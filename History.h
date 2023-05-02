//
// Created by Khanh Nguyen on 3/16/23.
//

#ifndef MULTITEXT_HISTORY_H
#define MULTITEXT_HISTORY_H

#include "HistoryNode.h"
#include <stack>
class History
{
public:
    static void push(const HistoryNode & node);
    static void push(GUIComponent * component, Snapshot * snapshot);

    static void pop();
    static Snapshot * top();
    static void print();
    static int size();
private:
    static std::stack<HistoryNode> stack;
    static void apply();

};


#endif //MULTITEXT_HISTORY_H
