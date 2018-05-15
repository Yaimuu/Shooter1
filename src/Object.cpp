#include "Object.h"

Object::Object(double x, double y)
{
    m_x = x;
    m_y = y;
    m_width = 20;
    m_height = 20;
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(3,3));
    rect.setFillColor(sf::Color::Blue);
    for(int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_width; j++)
        {
            rect.setPosition(sf::Vector2f(m_x + (j*3), m_y + (i*3)));
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

void Object::HitBox(Player &player)
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
                    bullets.erase(bullets.begin() + i);
                    m_body.erase(m_body.begin() + j);
                }
            }
            //std::cout << "Touche" << std::endl;
        }
    }
    player.SetBullets(bullets);
}

double Object::GetBodySize()
{
    return m_body.size();
}

void Object::Explosion()
{
    double x, y, speedx, speedy;
    speedx = rand() % 2 - 2;
    speedy = rand() % 2 - 2;
    if(m_body.size()/(m_width*m_height) < 0.5)
    {
        for(int j = 0; j < m_body.size(); j++)
        {
            speedx = rand()/2 % 4 - 2;
            speedy = rand()/2 % 4 - 2;
            x = m_body[j].getPosition().x;
            y = m_body[j].getPosition().y;
            m_body[j].setPosition(x + speedx, y + speedy);
        }
    }

}
