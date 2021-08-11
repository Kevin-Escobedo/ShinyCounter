#include "Window.hpp"

Window::Window(const char* title, const unsigned int x, const unsigned int y)
:screen(), dimensions(), name(title)
{
    setDimensions(x, y);

    screen.create(sf::VideoMode(dimensions.x, dimensions.y), name);//, sf::Style::Titlebar | sf::Style::Close);
    screen.setFramerateLimit(FRAMERATE);
}

Window::Window(const char* title, const sf::Vector2u& screenDimensions)
:screen(), dimensions(), name(title)
{
    setDimensions(screenDimensions);

    screen.create(sf::VideoMode(dimensions.x, dimensions.y), name);//, sf::Style::Titlebar | sf::Style::Close);
    screen.setFramerateLimit(FRAMERATE);
}

Window::Window(const Window& w)
:screen(), dimensions(), name(w.name)
{
    setDimensions(w.dimensions);

    screen.create(sf::VideoMode(dimensions.x, dimensions.y), name);//, sf::Style::Titlebar | sf::Style::Close);
    screen.setFramerateLimit(FRAMERATE);
}

Window& Window::operator =(const Window& w)
{
    setDimensions(w.dimensions);

    screen.create(sf::VideoMode(dimensions.x, dimensions.y), name);//, sf::Style::Titlebar | sf::Style::Close);
    screen.setFramerateLimit(FRAMERATE);

    return *this;
}

sf::Vector2u Window::getDimensions()
{
    return dimensions;
}

Window::~Window()
{
    if(screen.isOpen())
    {
        screen.close();
    }
}

std::ostream& operator <<(std::ostream& os, const Window& w)
{
    os<<"Name: "<<w.name<<std::endl;
    os<<"Dimensions: ("<<w.dimensions.x<<", "<<w.dimensions.y<<")";

    return os;
}

void Window::setDimensions(const unsigned int x, const unsigned int y)
{
    dimensions.x = x;
    dimensions.y = y;
}

void Window::setDimensions(const sf::Vector2u& screenDimensions)
{
    dimensions.x = screenDimensions.x;
    dimensions.y = screenDimensions.y;
}
