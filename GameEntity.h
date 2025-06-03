#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <tuple>

class GameEntity {
public:
    enum GameEntityType { ExplosionType, MineType, NoneType, ShipType };

protected:
    std::tuple<int, int> position;
    GameEntityType type;

public:
    GameEntity(int x, int y, GameEntityType type);
    std::tuple<int, int> getPos() const;
    GameEntityType getType() const;
};

#endif