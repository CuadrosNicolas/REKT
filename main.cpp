#include <SFML/Graphics.hpp>
#include "Ressources.h"
#include <vector>
#include <iostream>
#include <string>
#include "Mouse.h"
#include "Dock.h"
#include "Page.h"
#include <math.h>
using namespace std;
bool mouseInWindow(sf::Vector2f mousePosition,sf::Vector2u windowSize)
{
    return !((mousePosition.x <= 0 || mousePosition.x >= windowSize.x) &&
    (mousePosition.y<=0 || mousePosition.y >= windowSize.y));
}
int main(int argc,char* argv[])
{
    int pageIndex = 0;
    if(argc>2)
    {
        std::cout << "ERREUR il ne peut pas y avoir plus de 1 argument.";
    }
    else if(argc==2)
    {
        pageIndex = std::atoi(argv[1]);
    }
    Ressources::loadRessources();
    Ressources::actualPageIndex = pageIndex;
    Ressources::updateActualPage();
    sf::RenderWindow window(sf::VideoMode(500, 500), "REKT Editor");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Dock d(sf::Vector2f(window.getSize().x, window.getSize().y));
    sf::View HUD(sf::FloatRect(0, 0, 500, 500));
    sf::View PageView(sf::FloatRect(0, 0, 500, 500));
    window.setView(sf::View(HUD));
    sf::Vector2f mousePosition = sf::Vector2f(-1,-1);
    sf::Vector2i previousPosition;
    bool moveView = false;
    const float zoomAmount = 1.1;
    int nbZoom = 0;
    bool dockPressed;
    while (window.isOpen())
    {
        sf::Event event;
        MouseState state = MouseState::NOT_PRESSED;
        dockPressed = false;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Num1)
                {
                    Dock::setWrite();
                }
                if (event.key.code == sf::Keyboard::Num2)
                {
                    Dock::setErase();
                }
                if (event.key.code == sf::Keyboard::Q)
                {
                    Ressources::decIndex(&d);
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    Ressources::incIndex(&d);
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    Ressources::actualPage->screenShot();
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseInWindow(mousePosition,window.getSize()))
            {
                state = MouseState::PRESSED;
            }
            else
            {
                state = MouseState::NOT_PRESSED;
            }
            if (event.type == sf::Event::Closed)
            {
                Ressources::actualPage->save();
                window.close();
            }
            //event on dock
            window.setView(HUD);
            mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            MouseManager::setState(mousePosition, state);
            dockPressed = d.updateDock(MouseManager::getState());
            //Move page view event
            window.setView(PageView);
            if(!dockPressed)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                MouseManager::setState(mousePosition, state);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) == true && moveView == false)
                {
                    moveView = true;
                    previousPosition = sf::Mouse::getPosition(window);
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) == false)
                {
                    moveView = false;
                }
                if (event.type == sf::Event::MouseMoved && moveView == true)
                {
                    sf::Vector2i actualPos = sf::Mouse::getPosition(window);
                    sf::Vector2f moveVec;
                    if (nbZoom != 0)
                        moveVec = sf::Vector2f((previousPosition - actualPos).x * (std::pow(zoomAmount,nbZoom)), (previousPosition - actualPos).y * (std::pow(zoomAmount,nbZoom)));
                    else
                        moveVec = sf::Vector2f((previousPosition - actualPos).x, (previousPosition - actualPos).y);
                    PageView.move(moveVec);
                    previousPosition = actualPos;
                }
                if (event.type == sf::Event::MouseWheelScrolled)
                {
                    if (event.mouseWheelScroll.delta > 0)
                    {
                        PageView.zoom((1.f / zoomAmount));
                        nbZoom--;
                    }
                    else if (event.mouseWheelScroll.delta < 0)
                    {
                        PageView.zoom((zoomAmount));
                        nbZoom++;
                    }
                }
                if (event.type == sf::Event::Resized)
                {
                    PageView.setSize(event.size.width, event.size.height);
                    PageView.zoom((pow(zoomAmount,nbZoom)));
                }
                MouseManager::updatePage(Ressources::actualPage);
            }
        }
        d.updateState();
        window.clear(Ressources::background);
        window.setView(PageView);
        window.draw(*Ressources::actualPage);
        window.setView(HUD);
        window.draw(d);
        window.display();
    }

    return 0;
}