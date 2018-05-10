#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "Player.h"
#include "Bullet.h"

class Object
{
    public:
        Object(double x, double y);
        virtual ~Object();
        void Afficher(sf::RenderWindow &fenetre);
        void HitBox(Player player);


    protected:

    private:
        std::vector<sf::RectangleShape> m_body;
        double m_x, m_y, m_width, m_height;
};

#endif // OBJECT_H
