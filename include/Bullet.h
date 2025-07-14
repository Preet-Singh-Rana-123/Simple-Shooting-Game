//
// Created by Preet Rana on 13/07/25.
//

#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>


class Bullet {
    public:
    sf::CircleShape shape;
    sf::Vector2f currentVelocity;
    float maxSpeed;

    Bullet(float radius);
};



#endif //BULLET_H
