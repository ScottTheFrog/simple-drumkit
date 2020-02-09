#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640,360), "Drumset simulator");
    window.setFramerateLimit(60);

    sf::RectangleShape kick(sf::Vector2f(64.0f,64.0f));

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

        }

        window.clear();
        window.draw(kick);
        window.display();
    }

    return 0;
}

