#include <iostream>
#include "Component.h"
#include "Engine.h"

unsigned int Component::mLastUniqueId = 0;

Component::Component(GameObject * goParent)
{
	mUniqueId = GetNextUniqueId();
	SetParent(goParent);
}

Component::~Component()
{
}

void Component::Update()
{
	//std::cout << "[Component] Update()" << std::endl;
}

void Component::Render()
{
	//std::cout << "[Component] Render()" << std::endl;
}