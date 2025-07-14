//
// Created by Preet Rana on 13/07/25.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>

#include "../include/Bullet.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shooting Game", sf::Style::Default);
    window.setFramerateLimit(60);

    //Enemies
    sf::RectangleShape enemy(sf::Vector2f(50.f,50.f));
    enemy.setFillColor(sf::Color::Magenta);
    std::vector<sf::RectangleShape> enemies;
    int spawnTimer = 80;

    //Bullets
    Bullet b1(5.f);
    std::vector<Bullet> bullets;

    //Player
    sf::CircleShape player(30.f);
    player.setFillColor(sf::Color::White);
    player.setPosition(sf::Vector2f(200.f,200.f));

    // Vectors
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosition;
    sf::Vector2f aimDirection;
    sf::Vector2f aimNormal;

    // health bar
    int health = 3;
    sf::RectangleShape hpBar(sf::Vector2f(20.f * health,20.f));
    hpBar.setFillColor(sf::Color::Red);
    hpBar.setPosition(sf::Vector2f(window.getSize().x - hpBar.getSize().x - 10.f, 10.f));

    // Points
    int points = 0;

    // Fonts
    sf::Font font;
    if (!font.loadFromFile("/Users/preetrana/Documents/C++ learn/SFML_LEARN/Project2/Font/Roboto-Light.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    // Health
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(17);
    text.setString("Health");
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(window.getSize().x - hpBar.getSize().x - 65.f,10.f));

    // Point
    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(17);
    text2.setString("Point = " + std::to_string(points));
    text2.setFillColor(sf::Color::White);
    text2.setPosition(10.f,10.f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update
        // Vector
        playerCenter = sf::Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
        mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        aimDirection = mousePosition - playerCenter;
        aimNormal = aimDirection / static_cast<float>(sqrt(pow(aimDirection.x, 2) + pow(aimDirection.y, 2)));

        //Player

        sf::Vector2f playerPosition = player.getPosition();
        float playerRadius = player.getRadius();
        player.setOrigin(playerRadius, playerRadius);

        if (playerPosition.x - playerRadius < 0) {
            player.setPosition(playerRadius, playerPosition.y);
        }else if (playerPosition.x + playerRadius > window.getSize().x) {
            player.setPosition(window.getSize().x - playerRadius, playerPosition.y);
        }else if (playerPosition.y - playerRadius < 0) {
            player.setPosition(playerPosition.x, playerRadius);
        }else if (playerPosition.y + playerRadius > window.getSize().y) {
            player.setPosition(playerPosition.x, window.getSize().y - playerRadius);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-10.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(10.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.move(0.f, -10.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.move(0.f, 10.f);
        }

        // Bullet shoot
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            b1.shape.setPosition(playerCenter);
            b1.currentVelocity = aimNormal * b1.maxSpeed;
            bullets.push_back(Bullet(b1));
        }

        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].shape.move(bullets[i].currentVelocity);
        }

        for (int i = 0; i < bullets.size(); i++) {
            if (bullets[i].shape.getPosition().x < 0) {
                bullets.erase(bullets.begin() + i);
            }else if (bullets[i].shape.getPosition().x > window.getSize().x) {
                bullets.erase(bullets.begin() + i);
            }else if (bullets[i].shape.getPosition().y < 0) {
                bullets.erase(bullets.begin() + i);
            }else if (bullets[i].shape.getPosition().y > window.getSize().y) {
                bullets.erase(bullets.begin() + i);
            }
        }

        // Enemies
        if (spawnTimer < 80) {
            spawnTimer++;
        }

        if (spawnTimer >= 80) {
            enemy.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
            enemies.push_back(enemy);
            spawnTimer = 0;
        }

        // collision
        for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < enemies.size(); j++) {
                if (bullets[i].shape.getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                    bullets.erase(bullets.begin() + i);
                    enemies.erase(enemies.begin() + j);
                    points++;
                }
            }
        }

        // Health Bar
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i].getGlobalBounds().intersects(player.getGlobalBounds())) {
                enemies.erase(enemies.begin() + i);
                if (health>0)
                    health--;
            }
        }

        hpBar.setSize(sf::Vector2f(health*20.f,20.f));

        // Points
        text2.setString("Point = " + std::to_string(points));

        // Draw
        window.clear();

        for (int i=0;i<enemies.size();i++) {
            window.draw(enemies[i]);
        }

        window.draw(player);

        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].shape);
        }

        window.draw(hpBar);

        window.draw(text);
        window.draw(text2);

        window.display();
    }

    return 0;
}
