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

    m_bullet.setSize(sf::Vector2f(5,2));
    m_bullet.setFillColor(sf::Color::Black);
    m_bullet.setPosition(m_x,m_y);
    m_range = 1000;
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::Afficher(sf::RenderWindow &fenetre)
{
    sf::Vector2i posSouris;
    posSouris = sf::Mouse::getPosition(fenetre);
    float center_x = m_bullet.getPosition().x;
    float center_y = m_bullet.getPosition().y;

    m_bullet.setRotation(argument2(center_x, center_y, posSouris.x, posSouris.y)*180/M_PI);

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

double Bullet::GetPosX()
{
    return m_x;
}

double Bullet::GetPosY()
{
    return m_y;
}

