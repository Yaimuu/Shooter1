#include "Object.h"

Object::Object(double x, double y)
{
    m_x = x;
    m_y = y;
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(5,5));
    rect.setFillColor(sf::Color::Blue);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            rect.setPosition(sf::Vector2f(m_x + (j*5), m_y + (i*5)));
            m_body.push_back(rect);
        }
    }
}

Object::~Object()
{
    //dtor
}

void Object::Afficher(sf::RenderWindow &fenetre)
{
    for(int j = 0; j < m_body.size(); j++)
    {
        fenetre.draw(m_body[j]);
    }
    //std::cout << m_body.size() << std::endl;
}

void Object::HitBox(Player player)
{

}
