//
// Created by Khanh Nguyen on 3/23/23.
//

#ifndef MULTITEXT_WORD_H
#define MULTITEXT_WORD_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Word : public sf::Text
{
public:
    Word();
    Word(std::string string);
    std::string getString();
    std::string getString() const;

    int getPriority();
    void addPriority(int point);
    void setWordPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds();
private:
    std::string string;
    void init();
    void setUpString();
    sf::Font font;
    int priority;

    friend bool operator > (const Word & lhs, const Word & rhs);
    friend bool operator < (const Word & lhs, const Word & rhs);
    friend bool operator == (const Word & lhs, const Word & rhs);
    friend bool operator != (const Word & lhs, const Word & rhs);



};


#endif //MULTITEXT_WORD_H
