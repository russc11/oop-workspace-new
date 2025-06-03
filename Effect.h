#ifndef EFFECT_H
#define EFFECT_H

class GameEntity;

class Effect {
public:
    virtual void apply(GameEntity& entity) = 0;
    virtual ~Effect() = default;
};

#endif