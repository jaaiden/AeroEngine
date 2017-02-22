#include <iostream>
#include "GameObject.h"
#include "TransformComponent.h"
#include "PlayerController.h"
#include "ImageComponent.h"

GameObject::GameObject(std::string &aName)
{
	mName = aName;
	TransformComponent* trComp = new TransformComponent(this, Vector2(0, 0), Vector2(0, 0), Vector2(128, 128));
	transform = trComp;
	std::cout << mName.c_str() << " > transform:\n\tposition.x: " << transform->position.x << "\n\tposition.y: " << transform->position.y << "\n\trotation.x: " << transform->rotation.x << "\n\trotation.y: " << transform->rotation.y << "\n\tscale.x: " << transform->scale.x << "\n\tscale.y: " << transform->scale.y << std::endl;

	AddComponent(trComp);
}


GameObject::~GameObject()
{
	for (ComponentContainer::iterator itr = mComponents.begin(); itr != mComponents.end(); itr++)
	{
		//delete itr->second;
		//itr->second = 0;
	}
	//mComponents.clear();
}

void GameObject::Update()
{
	//std::cout << mName.c_str() << " GameObject::Update" << std::endl;
	for (ComponentContainer::iterator itr = mComponents.begin(); itr != mComponents.end(); itr++)
	{
		itr->second->Update();
	}
}

void GameObject::Render()
{
	//std::cout << mName.c_str() << " GameObject::Update" << std::endl;
	for (ComponentContainer::iterator itr = mComponents.begin(); itr != mComponents.end(); itr++)
	{
		itr->second->Render();
	}
}

void GameObject::AddComponent(Component * comp)
{
	if (mComponents.begin() == mComponents.end())
		mComponents[0] = comp;
	else
		mComponents[mComponents.rbegin()->first + 1] = comp;
}