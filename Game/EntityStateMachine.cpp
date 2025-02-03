#include "EntityStateMachine.h"
#include "EntityIdleState.h"

void EntityStateMachine::Initialize(EntityState* startingState)
{
	currentState = startingState;
	currentState->EnterState();
}

void EntityStateMachine::ChangeState(EntityState* newState)
{
	currentState->ExitState();
	currentState = newState;
	currentState->EnterState();
}
