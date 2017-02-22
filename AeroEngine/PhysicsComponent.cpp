#include <iostream>
#include <Box2D\Box2D.h>
#include "GameObject.h"
#include "PhysicsManager.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"

PhysicsComponent::PhysicsComponent(GameObject* goParent) : Component(goParent)
{
	// Super long dynamic body creation function yay
	physBody = PhysicsManager::GetInstance()->CreateDynamicBody(
		parent->GetName(),
		parent->GetComponent<TransformComponent>()->scale.x,
		parent->GetComponent<TransformComponent>()->scale.y,
		10.0f, 1.0f);
}

void PhysicsComponent::Update()
{
	parent->GetComponent<TransformComponent>()->position = Vector2::ConvertB2Vec2((*physBody).GetPosition());
}