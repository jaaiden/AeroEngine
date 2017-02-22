#pragma once
#include <string>
#include "Component.h"
#include "GameObject.h"

// This class creates new components
class ComponentFactory
{
public:
	ComponentFactory() {}
	~ComponentFactory();

	static Component *CreateComponent(const std::string &aCompType, GameObject* aGameObject);

private:
};