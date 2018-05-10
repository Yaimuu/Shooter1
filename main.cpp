#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Object.h"

Player player = Player();
int countObjects = 0;
int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    app.setFramerateLimit(120);
    std::vector<Object> objets;
    sf::Vector2i posSouris;


	// Start the game loop
    while (app.isOpen())
    {
        posSouris = sf::Mouse::getPosition(app);
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        player.Move(event);
        player.Focus(app);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            player.Tirer(app);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            if(countObjects % 6 == 0)
            {
                objets.push_back(Object(posSouris.x, posSouris.y));
            }

            countObjects++;
        }


        app.clear();

        if(objets.size() != 0)
        {
            for(int i = 0; i < objets.size(); i++)
            {
                objets[i].Afficher(app);
            }
            std::cout << objets.size() << std::endl;
        }


        player.Afficher(app);
        player.TestBullet();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
