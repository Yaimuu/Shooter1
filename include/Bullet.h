#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <math.h>

class Bullet
{
    public:
        Bullet(double x, double y, float angle, double xDest, double yDest);
        virtual ~Bullet();
        void Afficher(sf::RenderWindow &fenetre);
        void Move();
        double GetRange();
        double GetDist();

    protected:

    private:
        sf::RectangleShape m_bullet;
        double m_Ox, m_Oy, m_x, m_y, m_pasX, m_pasY, m_range, m_speed;

};

#endif // BULLET_H
