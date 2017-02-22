#include <iostream>
#include "AIController.h"
#include "Time.h"
#include "Random.h"

AIController::AIController(GameObject *goParent) : Component(goParent)
{}


AIController::~AIController()
{}

void AIController::SetNextMoveDirection()
{
	int rand = Random::range(MoveDirection::LEFT, MoveDirection::DOWN);
	switch (rand)
	{
		case 1:
			SetMoveDirection(MoveDirection::LEFT); break;
		case 2:
			SetMoveDirection(MoveDirection::RIGHT); break;
		case 3:
			SetMoveDirection(MoveDirection::UP); break;
		case 4:
			SetMoveDirection(MoveDirection::DOWN); break;
	}
	std::cout << "AIController::SetNextMoveDirection()\n\t> Direction: " << TransformComponent::GetMoveDirectionName(GetMoveDirection()) << " (RandomInt: " << rand << ")" << std::endl;
}

void AIController::Update()
{
	//std::cout << "AIController::Update()" << std::endl;
	curMoveTime += Time::GetDeltaTimeInSeconds();
	if (curMoveTime >= timeToNextDir)
	{
		curMoveTime = 0;
		//std::cout << curMoveTime << std::endl;
		SetNextMoveDirection();
	}
}