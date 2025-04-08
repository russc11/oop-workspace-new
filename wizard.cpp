#include "wizard.h"
#include <iostream>

Wizard::Wizard(std::string name, int health, int damage, int mana) 
    : Player(name, health, damage), mana(mana) {}

void Wizard::castSpell(Player* opponent) {
    std::cout << name << " casts a spell on " << opponent->getName() << " for " << mana << " damage.\n";
    attack(opponent, mana);
}

int Wizard::getMana() const { return mana; }
void Wizard::setMana(int newMana) { mana = newMana; }