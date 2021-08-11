#ifndef SHINYCOUNTER_HPP
#define SHINYCOUNTER_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "ShinyDatabase.hpp"
#include "Window.hpp"
#include "Counter.hpp"

class ShinyCounter
{
private:
    Window w;
    Counter c;
    sf::Text text;
    sf::Font font;
    const char* targetHunt = nullptr;

public:
    ShinyCounter(const char* name, const unsigned int x, const unsigned int y, const char* target);
    ShinyCounter(const char* name, const sf::Vector2u& dimensions, const char* target);
    ShinyCounter(const ShinyCounter& sc);
    ShinyCounter& operator =(const ShinyCounter& sc);
    ~ShinyCounter();
    void run();

private:
    static void formatComma(std::string& count);
};

#endif /* SHINYCOUNTER_HPP */
