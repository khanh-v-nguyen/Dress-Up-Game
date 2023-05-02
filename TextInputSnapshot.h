//
// Created by Khanh Nguyen on 3/17/23.
//

#ifndef MULTITEXT_TEXTINPUTSNAPSHOT_H
#define MULTITEXT_TEXTINPUTSNAPSHOT_H

#include "Snapshot.h"

class TextInputSnapshot : public Snapshot
{
public:
    TextInputSnapshot();

    void setString(std::string string);

    std::string getString();

    void applyInstructions() override;


private:
    std::string string;


};


#endif //MULTITEXT_TEXTINPUTSNAPSHOT_H
