#include "EntityFlashState.h"

#include "EntityFollowState.h"
#include "RectangleRenderer.h"
#include "RectangleRenderer.h"

#include <iostream>

EntityFlashState::EntityFlashState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine): EntityState(_entity, _entityStateMachine) {}

void EntityFlashState::EnterState()
{
	std::cout << "Je flash" << '\n';
	entity->GetOwner()->GetComponent<RectangleRenderer>()->SetColor(sf::Color::Red);
}

void EntityFlashState::ExitState()
{
	entity->GetOwner()->GetComponent<RectangleRenderer>()->SetColor(sf::Color::Yellow);
}

void EntityFlashState::Update(float _delta_time)
{

	if (!entity->isInFlashRange)
	{
		entityStateMachine->ChangeState(entity->entityFollowState);
	}
}
