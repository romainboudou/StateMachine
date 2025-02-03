#include "FriendlySquare.h"

#include "EntityFlashState.h"
#include "EntityFollowState.h"
#include "EntityIdleState.h"

#include <iostream>

void FriendlySquare::Initialize()
{
	entityStateMachine = new EntityStateMachine;
	entityIdleState = new EntityIdleState(this, entityStateMachine);
	entityFollowState = new EntityFollowState(this, entityStateMachine);
	entityFlashState = new EntityFlashState(this, entityStateMachine);

	entityStateMachine->Initialize(entityIdleState);

	player = GetOwner()->GetOwner()->FindGameObject("Player");
}

void FriendlySquare::Update(float _delta_time)
{
	RectangleCollider* playerCollider = player->GetComponent<RectangleCollider>();
	isInFollowRange = followRange->CheckCollision(*playerCollider);
	isInFlashRange = flashRange->CheckCollision(*playerCollider);

	entityStateMachine->GetState()->Update(_delta_time);
}

void FriendlySquare::DetectNeighbours()
{
    neighbours.clear();

    RectangleCollider* rectangleCollider = GetOwner()->GetComponent<RectangleCollider>();
    const auto& colliders = RectangleCollider::GetColliders();

    for (const auto& collider : colliders)
    {
        if (collider != rectangleCollider && followRange->CheckCollision(*collider))
        {
            FriendlySquare* neighbourSquare = collider->GetOwner()->GetComponent<FriendlySquare>();
            if (neighbourSquare)
            {
                neighbours.push_back(neighbourSquare);
            }
        }
    }
}