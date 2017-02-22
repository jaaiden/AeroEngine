#pragma once
#include <string>
#include "Component.h"
#include "Vector2.h"

class GameObject;

enum MoveDirection
{
	NONE, LEFT, RIGHT, UP, DOWN
};

class TransformComponent : public Component
{
public:
	TransformComponent(GameObject* goParent, Vector2 transformPosition = Vector2(0, 0), Vector2 transformRotation = Vector2(0, 0), Vector2 transformScale = Vector2(0, 0));
	~TransformComponent();

	Vector2 position, rotation, scale = Vector2(0, 0);

	inline Vector2 GetPosition() { return position; }
	inline void SetPosition(Vector2 aPosition) { position = aPosition; }

	inline Vector2 GetRotation() { return rotation; }
	inline void SetRotation(Vector2 aRotation) { rotation = aRotation; }

	inline Vector2 GetScale() { return scale; }
	inline void SetScale(Vector2 aScale) { scale = aScale; }

	inline float GetMoveSpeed() { return movementSpeed; }
	inline void SetMoveSpeed(float aSpeed) { movementSpeed = aSpeed; }

	// Move the GameObject's X position
	void MoveX(float amountToMove);

	// Move the GameObject's Y position
	void MoveY(float amountToMove);

	inline MoveDirection GetCurrentDirection() { return currentDir; }
	inline void SetMoveDirection(MoveDirection moveDir) { currentDir = moveDir; }

	void SendDataToJson(nlohmann::json &jsonData);

	static std::string GetMoveDirectionName(MoveDirection moveDir)
	{
		switch (moveDir)
		{
			case LEFT:
				return "Left"; break;
			case RIGHT:
				return "Right"; break;
			case UP:
				return "Up"; break;
			case DOWN:
				return "Down"; break;
		}
	}

private:
	float movementSpeed;
	MoveDirection currentDir;
};

