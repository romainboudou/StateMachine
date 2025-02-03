#include "EntityIdleState.h"
#include "EntityFollowState.h"
#include "EntityFlashState.h"
#include "RectangleRenderer.h"

#include <iostream>

void EntityIdleState::EnterState()
{
    std::cout << "Je idle" << std::endl;
    entity->leader = entity;
    entity->isLeader = true;
}

void EntityIdleState::Update(float _delta_Time)
{
    if (entity->isInFollowRange)
    {
        entityStateMachine->ChangeState(entity->entityFollowState);
    }
    else
    {
        entity->DetectNeighbours();

        for (FriendlySquare* neighbour : entity->GetNeighbours())
        {
            if (neighbour->entityStateMachine->GetState() == neighbour->entityFollowState)
            {
                entity->leader = neighbour->leader;
                entity->isLeader = false;
                entityStateMachine->ChangeState(entity->entityFollowState);

                std::cout << "Je suis un esclave" << "\n";
                break;
            }
        }
    }
}
