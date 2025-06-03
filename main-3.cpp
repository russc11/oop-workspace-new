#include "Game.h"
#include <iostream>

std::vector<GameEntity> Game::getEntities() const {
    return entities;
}

void Game::setEntities(const std::vector<GameEntity>& newEntities) {
    entities = newEntities;
}

std::vector<GameEntity> Game::initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
    entities.clear();

    for (int i = 0; i < numShips; ++i) {
        auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
        entities.emplace_back(Ship(std::get<0>(pos), std::get<1>(pos)));
    }

    for (int i = 0; i < numMines; ++i) {
        auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
        entities.emplace_back(Mine(std::get<0>(pos), std::get<1>(pos)));
    }
    
    return entities;
}

void Game::gameLoop(int maxIterations, double mineDistanceThreshold) {
    for (int i = 0; i < maxIterations; ++i) {
        for (auto& entity : entities) {
            if (entity.getType() == GameEntity::ShipType) {
                Ship* ship = dynamic_cast<Ship*>(&entity);
                if (ship) {
                    ship->move(1, 0);
                }
            }
        }
        
        for (auto& entity1 : entities) {
            if (entity1.getType() != GameEntity::ShipType) continue;
            
            for (auto& entity2 : entities) {
                if (entity2.getType() != GameEntity::MineType) continue;
                
                double distance = Utils::calculateDistance(entity1.getPos(), entity2.getPos());
                if (distance <= mineDistanceThreshold) {
                    Mine* mine = dynamic_cast<Mine*>(&entity2);
                    if (mine) {
                        Explosion explosion = mine->explode();
                        explosion.apply(entity1);
                    }
                }
            }
        }

        bool allShipsDestroyed = true;
        for (const auto& entity : entities) {
            if (entity.getType() == GameEntity::ShipType) {
                allShipsDestroyed = false;
                break;
            }
        }
        
        if (allShipsDestroyed) {
            std::cout << "All ships destroyed! Game over after " << i+1 << " iterations.\n";
            return;
        }
    }
    
    std::cout << "Game completed " << maxIterations << " iterations.\n";
}

int main() {
    Game game;

    game.initGame(3, 5, 100, 100);
    
    game.gameLoop(100, 5.0);
    
    return 0;
}