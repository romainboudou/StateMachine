#pragma once

#include "EntityState.h"
#include "FriendlySquare.h"

class EntityIdleState : public EntityState
{
public:
    EntityIdleState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine) : EntityState(_entity, _entityStateMachine) {}

    void EnterState() override;

    void Update(float _delta_Time) override;
};
