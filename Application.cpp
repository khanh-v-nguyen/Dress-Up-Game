//
// Created by Khanh Nguyen on 2/22/23.
//

#include "Application.h"


Application::Application() : window({2400, 1400, 32}, "Text Input")
{

}

Application::Application(sf::VideoMode videoMode, std::string title) : window(videoMode, title)
{

}

void Application::run()
{
    runLoop();
}

void Application::runLoop()
{
    Typing typing;
    sf::Event event;

    TextInput ti;
    ti.setLabel("First name");
    ti.setPosition({30,100});
    SFMLFileTree tree;
    tree.push("Folder1");
    tree.push("Folder1/File1");

    sf::RectangleShape save({50,50});
    sf::RectangleShape load({50,50});
    load.setPosition({800,100});

    save.setFillColor(sf::Color::Green);
    load.setFillColor(sf::Color::Blue);

    Circle c;
    c.setPosition({500,500});

    CustomCursor cur;

    //ti.setLabelSize(30);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                window.close();
            }
            //typing.addEventHandler(window, event);
            ti.addEventHandler(window, event);
            tree.eventHandler(window,event);

            c.eventHandler(window, event);
            sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && MouseEvents::isClicked(save, window))
            {
                //save.getGlobalBounds().contains(mpos);
                SaveCircle::save(c, "circleSettings.txt");
            }
            else if(MouseEvents::isClicked(load, window))
            {
                SaveCircle::load(c, "circleSettings.txt");
            }
        }

        cur.eventHandler(window,event);
        ti.loopingEventHandler();

        window.clear();


        //window.draw(menu);
        window.draw(ti);

        //window.draw(save);
        //window.draw(load);
        //window.draw(c);
        //window.draw(sort);

        window.draw(tree);
        window.draw(cur);
        window.display();
    }

}
