//
// Created by Khanh Nguyen on 3/19/23.
//

#ifndef MULTITEXT_LABEL_H
#define MULTITEXT_LABEL_H

#include <SFML/Graphics.hpp>
class Label : public sf::Text
{
public:
    Label();
    Label(std::string name);
    void setLabelSize(sf::Vector2f size);
    void setLabelPosition(sf::Vector2f position);

private:
    void init();
    void setUpText();
//    sf::Text text;
    sf::Font font;
};


#endif //MULTITEXT_LABEL_H
