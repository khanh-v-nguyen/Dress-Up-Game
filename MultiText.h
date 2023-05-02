//
// Created by Khanh Nguyen on 3/1/23.
//

#ifndef MULTITEXT_MULTITEXT_H
#define MULTITEXT_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include "Letter.h"
#include "GUIComponent.h"
#include "MultiTextSnapshot.h"
#include <list>
class MultiText : public sf::Drawable
{
public:
    MultiText();
    std::list<Letter> list;

    void push(Letter letter);
    void push(std::string string);
    void pop_back();
    void draw(sf::RenderTarget &target, sf::RenderStates states);
    void setPosition(sf::Vector2f initialPos);
    Letter back();
    bool empty();
    Letter front();

    std::string getString(std::list<Letter>::iterator begin, std::list<Letter>::iterator end);

private:


    static sf::Vector2f initialPosition;

public:

    std::string getString();
    void setString(std::string string);

    sf::Font font;
    std::list<Letter>::iterator begin();
    std::list<Letter>::iterator end();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::list<Letter>::iterator it;

};


#endif //MULTITEXT_MULTITEXT_H
