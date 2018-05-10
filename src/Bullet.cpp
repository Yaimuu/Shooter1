#include "Bullet.h"

Bullet::Bullet(double x, double y, float angle, double xDest, double yDest)
{
    m_x = x;
    m_y = y;
    m_Ox = x;
    m_Oy = y;
    m_speed = 5;
    m_pasX = cos(M_PI*angle/180) * m_speed;
    m_pasY = sin(M_PI*angle/180) * m_speed;

    m_bullet.setSize(sf::Vector2f(5,5));
    m_bullet.setFillColor(sf::Color::White);
    m_bullet.setPosition(m_x,m_y);
    m_range = 1000;
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::Afficher(sf::RenderWindow &fenetre)
{
    fenetre.draw(m_bullet);
}

void Bullet::Move()
{
    m_x += m_pasX;
    m_y += m_pasY;
    m_bullet.setPosition(m_x,m_y);
}

double Bullet::GetRange()
{
    return m_range;
}

double Bullet::GetDist()
{
    return abs(m_Ox - m_x) + abs(m_Oy - m_y);
}
