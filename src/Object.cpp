#include "Object.h"

Object::Object(double x, double y)
{
    m_x = x;
    m_y = y;
    m_width = 4;
    m_height = 4;
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(5,5));
    rect.setFillColor(sf::Color::Blue);
    for(int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_width; j++)
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
    std::vector<Bullet> bullets;
    double x, y, xBody, yBody;
    bullets = player.GetBullets();
    for(int i = 0; i < bullets.size(); i++)
    {
        x = bullets[i].GetPosX();
        y = bullets[i].GetPosY();
        if((x >= m_x && x <= m_x + m_width*5) && (y >= m_y && y <= m_y + m_height*5) )
        {
            for(int j = 0; j < m_body.size(); j++)
            {
                xBody = m_body[j].getPosition().x;
                yBody = m_body[j].getPosition().y;
                if((x >= xBody && x <= xBody + 5) && (y >= yBody && y <= yBody + 5))
                {
                    m_body.erase(m_body.begin() + j);
                }
            }
            //std::cout << "Touche" << std::endl;
        }
    }
}
