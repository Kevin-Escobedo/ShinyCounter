#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

class Window
{
public:
    sf::RenderWindow screen;

private:
    sf::Vector2u dimensions;
    const char* name;
    const unsigned int FRAMERATE = 60;

public:
    Window(const char* title, const unsigned int x, const unsigned int y);
    Window(const char* title, const sf::Vector2u& screenDimensions);
    Window(const Window& w);
    Window& operator =(const Window& w);
    sf::Vector2u getDimensions();
    ~Window();
    friend std::ostream& operator <<(std::ostream& os, const Window& w);
    void setDimensions(const unsigned int x, const unsigned int y);
    void setDimensions(const sf::Vector2u& screenDimensions);
};

#endif /* WINDOW_HPP */
