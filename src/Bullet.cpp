//
// Created by Preet Rana on 13/07/25.
//

#include "../include/Bullet.h"

Bullet::Bullet(float radius) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Green);

    maxSpeed = 15.f;
    currentVelocity = sf::Vector2f(0.f,0.f);
}
