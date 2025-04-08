#include "wizard.h"
#include "warrior.h"
#include <iostream>

int main() {
    Wizard wizard("Merlin", 100, 10, 20);
    Warrior warrior("Arthur", 150, 15, "Sword");

    Player* attacker = &wizard;
    Player* defender = &warrior;

    while (wizard.getHealth() > 0 && warrior.getHealth() > 0) {
        if (attacker == &wizard) {
            wizard.castSpell(defender);
        } else {
            warrior.swingWeapon(defender);
        }

        if (defender->getHealth() <= 0) break;

        Player* temp = attacker;
        attacker = defender;
        defender = temp;
    }

    std::cout << (wizard.getHealth() > 0 ? wizard.getName() : warrior.getName()) << " wins!\n";
    return 0;
}