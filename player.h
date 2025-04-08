#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
protected:
    std::string name;
    int health;
    int damage;

public:
    Player(std::string name, int health, int damage);
    void attack(Player* opponent, int damage);
    void takeDamage(int damage);
    std::string getName() const;
    void setName(std::string newName);
    int getHealth() const;
    void setHealth(int newHealth);
    int getDamage() const;
    void setDamage(int newDamage);
};

#endif 