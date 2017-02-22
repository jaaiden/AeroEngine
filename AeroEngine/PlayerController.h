#pragma once
#include "Component.h"
#include "TransformComponent.h"
class PlayerController : public Component
{
public:
	PlayerController(GameObject* goParent);
	~PlayerController();

	void Update();

private:
	TransformComponent *transform;
};

