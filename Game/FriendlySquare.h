#pragma once

#include "Entity.h" //classe parent

#include "EntityStateMachine.h" //state machine associée

//components
#include "RectangleTrigger.h"

class EntityStateMachine;
class EntityIdleState;
class EntityFollowState;
class EntityFlashState;

class FriendlySquare : public Entity
{
public:
	void Initialize();

	void Update(float _delta_time) override;

	bool isInFollowRange = false;
	bool isInFlashRange = false;

	EntityStateMachine* entityStateMachine;
	EntityIdleState* entityIdleState;
	EntityFollowState* entityFollowState;
	EntityFlashState* entityFlashState;

	GameObject* player;

	void SetFollowRange(RectangleTrigger* _followRange) { followRange = _followRange; }
	void SetFlashRange(RectangleTrigger* _flashRange) { flashRange = _flashRange; }

	void DetectNeighbours();
	std::vector<FriendlySquare*> GetNeighbours() { return neighbours; }

	FriendlySquare* leader = this;
	bool isLeader = true;

private :
	RectangleTrigger* followRange = nullptr;
	RectangleTrigger* flashRange = nullptr;

	std::vector<FriendlySquare*> neighbours;
};
