//
// Created by Khanh Nguyen on 3/9/23.
//

#ifndef MULTITEXT_TEXTINPUT_H
#define MULTITEXT_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Textbox.h"
#include "Typing.h"
#include "TextInputSnapshot.h"
#include "History.h"
#include "KeyShortcuts.h"
#include "Label.h"
#include "KeyShortcuts.h"
#include "WordSort.h"


class TextInput : public GUIComponent
{
public:
    TextInput();

    Snapshot * getSnapshot() override;

    void applySnapshot(Snapshot * snapshot) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void setLabel(std::string string);

    void setLabelSize(float size);

    void loopingEventHandler();

    void setPosition(sf::Vector2f position);

    sf::FloatRect getGlobalBounds();

    std::string getText();

private:

    void update() override;

    Textbox textbox;
    Typing typing;
    std::string string;
    Label label;
    FileReader<std::string> file;
    WordSort wordSort;

    void init();

    void setUpWordSort();

    void positionAll();


};


#endif //MULTITEXT_TEXTINPUT_H
