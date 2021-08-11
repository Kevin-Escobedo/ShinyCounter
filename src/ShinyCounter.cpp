#include "ShinyCounter.hpp"

ShinyCounter::ShinyCounter(const char* name, const unsigned int x, const unsigned int y, const char* target)
:w(name, x, y), c(), text(), font(), targetHunt(target)
{
    if(!font.loadFromFile("resources/sansation.ttf"))
    {

    }

    text.setFont(font);
    text.setCharacterSize(x / 10.f);
    text.setStyle(sf::Text::Regular);
}

ShinyCounter::ShinyCounter(const char* name, const sf::Vector2u& dimensions, const char* target)
:w(name, dimensions), c(), text(), font(), targetHunt(target)
{    
    if(!font.loadFromFile("resources/sansation.ttf"))
    {

    }

    text.setFont(font);
    text.setCharacterSize(dimensions.x/10.f);
    text.setStyle(sf::Text::Regular);
}

ShinyCounter::ShinyCounter(const ShinyCounter& sc)
:w(sc.w), c(sc.c), text(), font(), targetHunt(sc.targetHunt)
{
    if(!font.loadFromFile("resources/sansation.ttf"))
    {

    }

    text.setFont(font);
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Regular);
}

ShinyCounter& ShinyCounter::operator =(const ShinyCounter& sc)
{
    w = sc.w;
    c = sc.c;
    targetHunt = sc.targetHunt;

    if(!font.loadFromFile("resources/sansation.ttf"))
    {

    }

    text.setFont(font);
    text.setCharacterSize(w.getDimensions().x/10.f);
    text.setStyle(sf::Text::Regular);

    return *this;
}

ShinyCounter::~ShinyCounter()
{

}

void ShinyCounter::run()
{
    ShinyDatabase sd("hunts.db");
    c.setCount(sd.getCount(targetHunt));

    while(w.screen.isOpen())
    {
        sf::Event event;
        while(w.screen.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    w.screen.close();

                    const int currentCount = c.getCount();
                    sd.insertData(targetHunt, currentCount);

                    break;
                }

                case sf::Event::KeyReleased:
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Space:
                        {
                            c++;
                            
                            const int currentCount = c.getCount();
                            if(currentCount % 5 == 0)
                            {
                                sd.insertData(targetHunt, currentCount);
                            }

                            break;
                        }

                        case sf::Keyboard::BackSpace:
                        {
                            c--;

                            const int currentCount = c.getCount();
                            if(currentCount % 5 == 0)
                            {
                                sd.insertData(targetHunt, currentCount);
                            }

                            break;
                        }

                        default:
                        {
                            break;
                        }
                    }

                    break;
                }

                case sf::Event::Resized:
                {
                    const float newWidth = static_cast<float>(event.size.width);
                    const float newHeight = static_cast<float>(event.size.height);

                    sf::View view;
                    view.setSize(newWidth, newHeight);
                    view.setCenter(newWidth/2.f, newHeight/2.f);
                    w.screen.setView(view);

                    w.setDimensions(newWidth, newHeight);
                    text.setCharacterSize(w.getDimensions().x/10.f);

                    break;
                }

                default:
                {
                    break;
                }
            }
        }

        std::string currentCount = std::to_string(c.getCount());
        formatComma(currentCount);
        text.setString(currentCount);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        const sf::Vector2u windowDimensions = w.getDimensions();
        text.setPosition(sf::Vector2f(windowDimensions.x/2.0f, windowDimensions.y/2.0f));


        w.screen.clear();
        w.screen.draw(text);
        w.screen.display();
    }
}

void ShinyCounter::formatComma(std::string& count)
{
    int insertAt = count.length() - 3;
    while(insertAt > 0)
    {
        count.insert(insertAt, ",");
        insertAt -= 3;
    }
}
