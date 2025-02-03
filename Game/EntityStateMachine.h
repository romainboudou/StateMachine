#pragma once
#include "Component.h"

#include "EntityState.h" //template state

class EntityStateMachine
{
public :
	void Initialize(EntityState* startingState);

	void ChangeState(EntityState* newState);

	EntityState* GetState() { return currentState; }
	void SetState(EntityState* entityState) { currentState = entityState; }

private :
	EntityState* currentState = nullptr;
};
