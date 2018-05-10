#include "Player.h"
#include "../complex.h"

Player::Player()
{
    m_y = 400;
    m_x = 300;
    m_long = 30;
    m_larg = 20;
    m_rot = 90;
    m_speed = 1.5;
    m_player = sf::RectangleShape(sf::Vector2f(m_long,m_larg));
    m_player.setFillColor(sf::Color(255,0,0));
    //m_player.setOrigin(sf::Vector2f(m_x,m_y));
    m_player.setOrigin(m_long/2,m_larg/2);
    m_player.setPosition(m_x,m_y);
    //m_player.setRotation(m_rot);
}

Player::~Player()
{
    //dtor
}

void Player::Afficher(sf::RenderWindow &fenetre)
{

    for(int i = 0; i < m_bullets.size(); i++)
    {
        m_bullets[i].Move();
        m_bullets[i].Afficher(fenetre);
    }
    fenetre.draw(m_player);
}

void Player::SetPos(double x, double y)
{
    /*m_x = x;
    m_y = y;*/
    m_player.setPosition(m_x,m_y);
}

void Player::Move(sf::Event &event)
{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            m_y-=m_speed;
            SetPos(m_x, m_y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            m_y+=m_speed;
            SetPos(m_x, m_y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            m_x-=m_speed;
            SetPos(m_x, m_y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            m_x+=m_speed;
            SetPos(m_x, m_y);
        }
}

void Player::Focus(sf::RenderWindow &fenetre)
{
    sf::Vector2i posSouris;
    posSouris = sf::Mouse::getPosition(fenetre);
    float center_x = m_player.getPosition().x;
    float center_y = m_player.getPosition().y;

    m_rot = argument2(center_x, center_y, posSouris.x, posSouris.y);
    m_rot = m_rot*180/M_PI;

    //std::cout << m_rot << std::endl;

    m_player.setRotation(m_rot);
}

void Player::Tirer(sf::RenderWindow &fenetre)
{
    sf::Vector2i posSouris;
    posSouris = sf::Mouse::getPosition(fenetre);

    Bullet bullet = Bullet(m_x, m_y, m_rot, posSouris.x, posSouris.y);
    m_bullets.push_back(bullet);
}

void Player::TestBullet()
{
    for(int i = 0; i < m_bullets.size(); i++)
    {
        if(m_bullets[i].GetRange() <= m_bullets[i].GetDist())
        {
            m_bullets.erase(m_bullets.begin() + i);
        }

    }
}
