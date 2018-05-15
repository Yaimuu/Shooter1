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
double fire_rate = 2;
int main()
{
    std::srand(std::time(NULL));
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    app.setFramerateLimit(120);
    std::vector<Object> objets;
    sf::Vector2i posSouris;
    int mouseWheel;

	// Start the game loop
    while (app.isOpen())
    {
        srand((unsigned)time(0));
        sf::Event event;
        posSouris = sf::Mouse::getPosition(app);


        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            if(event.type == sf::Event::MouseWheelMoved)
            {
                mouseWheel = event.mouseWheel.delta;
                if(mouseWheel < 0)
                {
                    fire_rate += 0.1;
                    player.SetFireRate(fire_rate);
                    std::cout << fire_rate << std::endl;
                }
                else if(mouseWheel > 0 )
                {
                    fire_rate -= 0.1;
                    player.SetFireRate(fire_rate);
                    std::cout << fire_rate << std::endl;
                }
            }
        }

        player.Move(event);
        player.Focus(app);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            player.Tirer(app);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            if(countObjects % 10 == 0)
            {
                objets.push_back(Object(posSouris.x, posSouris.y));
            }

            countObjects++;
        }


        app.clear(sf::Color::White);

        if(objets.size() != 0)
        {
            for(int i = 0; i < objets.size(); i++)
            {
                objets[i].Explosion();
                objets[i].Afficher(app);
                objets[i].HitBox(player);
                if(objets[i].GetBodySize() == 0)
                {
                    objets.erase(objets.begin() + i);
                }
            }
            //std::cout << objets.size() << std::endl;
        }


        player.Afficher(app);
        player.TestBullet();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
