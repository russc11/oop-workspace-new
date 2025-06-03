#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"
#include <iostream>

// Implementations of the classes
GameEntity::GameEntity(int x, int y, GameEntityType type) 
    : position(std::make_tuple(x, y)), type(type) {}

std::tuple<int, int> GameEntity::getPos() const {
    return position;
}

GameEntity::GameEntityType GameEntity::getType() const {
    return type;
}

Ship::Ship(int x, int y) : GameEntity(x, y, ShipType) {}

void Ship::move(int dx, int dy) {
    int x = std::get<0>(position) + dx;
    int y = std::get<1>(position) + dy;
    position = std::make_tuple(x, y);
}

Mine::Mine(int x, int y) : GameEntity(x, y, MineType) {}

Explosion Mine::explode() {
    auto pos = getPos();
    type = NoneType;
    return Explosion(std::get<0>(pos), std::get<1>(pos));
}

Explosion::Explosion(int x, int y) : GameEntity(x, y, ExplosionType) {}

void Explosion::apply(GameEntity& entity) {
    entity = GameEntity(-1, -1, NoneType);
}

int main() {
    // Create a ship and a mine
    Ship ship(5, 5);
    Mine mine(10, 10);
    
    // Move the ship
    ship.move(1, 0);
    auto pos = ship.getPos();
    std::cout << "Ship moved to: (" << std::get<0>(pos) << ", " << std::get<1>(pos) << ")\n";
    
    // Explode the mine and apply to ship
    Explosion explosion = mine.explode();
    explosion.apply(ship);
    
    // Check ship status after explosion
    pos = ship.getPos();
    std::cout << "Ship after explosion: (" << std::get<0>(pos) << ", " << std::get<1>(pos) 
              << "), type: " << ship.getType() << std::endl;
    
    return 0;
}