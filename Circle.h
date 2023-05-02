//
// Created by Khanh Nguyen on 4/20/23.
//

#ifndef MULTITEXT_CIRCLE_H
#define MULTITEXT_CIRCLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Circle : public sf::Drawable
{
private:
    sf::CircleShape circle;
public:
    Circle();
    void eventHandler(sf::RenderWindow &window,sf::Event event);
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f pos);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //MULTITEXT_CIRCLE_H
