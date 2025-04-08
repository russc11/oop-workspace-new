#include "player.h"
#include <iostream>

Player::Player(std::string name, int health, int damage) 
    : name(name), health(health), damage(damage) {}

void Player::attack(Player* opponent, int damage) {
    opponent->takeDamage(damage);
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << name << " takes " << damage << " damage. Remaining health: " << health << "\n";
}

std::string Player::getName() const { return name; }
void Player::setName(std::string newName) { name = newName; }
int Player::getHealth() const { return health; }
void Player::setHealth(int newHealth) { health = newHealth; }
int Player::getDamage() const { return damage; }
void Player::setDamage(int newDamage) { damage = newDamage; }