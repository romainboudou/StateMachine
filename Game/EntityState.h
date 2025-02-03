#pragma once

#include "Component.h"

class FriendlySquare;
class EntityStateMachine;

class EntityState
{
public :
	EntityState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine)
	{
		entity = _entity;
		entityStateMachine = _entityStateMachine;
	}

	virtual void EnterState() {}

	virtual void ExitState() {}

	virtual void Update(float _delta_time) {}

protected :
	FriendlySquare* entity;
	EntityStateMachine* entityStateMachine;
};
