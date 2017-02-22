#include "PlayerController.h"
#include "GOManager.h"
#include "TransformComponent.h"
#include "Time.h"

PlayerController::PlayerController(GameObject* goParent) : Component(goParent)
{
	transform = goParent->GetComponent<TransformComponent>();
	//transform = GOManager::GetInstance()->GetGameObject(0).transform;
}

PlayerController::~PlayerController()
{}

void PlayerController::Update()
{
	MoveDirection currentDir = transform->GetCurrentDirection();

	switch (currentDir)
	{
		case NONE:
			break;
		case UP:
			transform->MoveY(1 * Time::GetDeltaTimeInSeconds());
			break;
		case DOWN:
			transform->MoveY(-(1 * Time::GetDeltaTimeInSeconds()));
			break;
		case RIGHT:
			transform->MoveX(1 * Time::GetDeltaTimeInSeconds());
			break;
		case LEFT:
			transform->MoveX(-(1 * Time::GetDeltaTimeInSeconds()));
			break;
	}
}