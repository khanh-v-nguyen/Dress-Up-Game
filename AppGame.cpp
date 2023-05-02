//
// Created by Khanh Nguyen on 4/23/23.
//

#include "AppGame.h"

AppGame::AppGame() : window({2400, 1400, 32}, "Dress Up")
{

}

AppGame::AppGame(sf::VideoMode videoMode, std::string title) : window(videoMode, title)
{

}

void AppGame::run()
{
    Images::setWindowSize(window);
    runLoop();
}

void AppGame::runLoop()
{
    sf::Event event;
    background.setTexture(&Images::getImage(BACKGROUND));
    background.setSize({static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)});
    OptionsBar bar;
    CustomCursor cursor;
    window.setMouseCursorVisible(false);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                window.close();
            }
            settings.eventHandler(window, event);
            bar.eventHandler(window,event);
        }
        settings.loopingEventHandler(window,event);
        cursor.eventHandler(window, event);

        window.clear();
        window.draw(background);
        window.draw(bar);
        window.draw(settings);
        window.draw(cursor);

        window.display();
    }
}

