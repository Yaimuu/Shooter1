#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <list>
#include "Bullet.h"
#include "../complex.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        void Afficher(sf::RenderWindow &fenetre);
        void Tirer(sf::RenderWindow &fenetre);
        void Focus(sf::RenderWindow &fenetre);
        void Move(sf::Event &event);
        void TestBullet();
        std::vector<Bullet> GetBullets();
        void SetBullets(std::vector<Bullet> bullets);
        void SetFireRate(double newFireRate);

    protected:

    private:
        void SetPos(double x, double y);
        sf::RectangleShape m_player;
        //std::vector<sf::RectangleShape> m_player;
        double m_x, m_y, m_long, m_larg, m_speed, m_fireRate, m_countFire;
        float m_rot;
        std::vector<Bullet> m_bullets;
};

#endif // PLAYER_H
