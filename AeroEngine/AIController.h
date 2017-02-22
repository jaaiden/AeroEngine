#pragma once
#include "Component.h"
#include "TransformComponent.h"
class AIController : public Component
{
public:
	AIController(GameObject *goParent);
	~AIController();

	inline MoveDirection GetMoveDirection() { return moveDir; }
	inline void SetMoveDirection(MoveDirection aMoveDirection) { moveDir = aMoveDirection; }
	void SetNextMoveDirection();

	void Update();

private:
	MoveDirection moveDir;
	double curMoveTime = 0;
	double timeToNextDir = 5;
};

