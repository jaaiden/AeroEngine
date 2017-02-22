#include <SDL.h>
#include "Json.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(GameObject* goParent, Vector2 transformPosition, Vector2 transformRotation, Vector2 transformScale) : Component(goParent)
{
	SetPosition(transformPosition);
	SetRotation(transformRotation);
	SetScale(transformScale);
	SetMoveSpeed(1);
}


TransformComponent::~TransformComponent()
{}

void TransformComponent::MoveX(float amountToMove)
{
	Vector2 newPos = GetPosition();
	newPos.x += (amountToMove)* GetMoveSpeed();
	SetPosition(newPos);
}

void TransformComponent::MoveY(float amountToMove)
{
	Vector2 newPos = GetPosition();
	newPos.y += (amountToMove)* GetMoveSpeed();
	SetPosition(newPos);
}

void TransformComponent::SendDataToJson(nlohmann::json & jsonData)
{
	jsonData["components"]["Transform"] = {
		{"position", {position.x, position.y}},
		{"rotation", {rotation.x, rotation.y}},
		{"scale", {scale.x, scale.y}}
	};
}