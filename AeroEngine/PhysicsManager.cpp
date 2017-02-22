#include "PhysicsManager.h"
INIT_SINGLETON(PhysicsManager);

PhysicsManager::PhysicsManager()
{
	world = std::make_unique<b2World>(gravity);
	physGroundDef.position.Set(0.0f, 10.0f);

	// Add ground to world
	AddBody(physGroundDef, physGroundBody);
	CreateBoxFixture(physGroundShape, 25.0f, 10.0f, physGroundBody, 0.0f);
}

void PhysicsManager::StepForward(float stepAmount)
{
	world->Step(stepAmount, velocityIterator, positionIterator);
}

void PhysicsManager::AddBody(const b2BodyDef &aBodyDef, b2Body* &aBody)
{
	aBody = world->CreateBody(&aBodyDef);
}

void PhysicsManager::CreateBoxFixture(b2PolygonShape & aPolyShape, float aWidth, float aHeight, b2Body * aBody, float aMass)
{
	physGroundShape.SetAsBox(aWidth, aHeight);
	physGroundBody->CreateFixture(&physGroundShape, aMass);
}

void PhysicsManager::CreateBodyDef(std::string aName, float aPosX, float aPosY)
{
	physBodyDefs[aName] = new b2BodyDef();
	physBodyDefs[aName]->type = b2_dynamicBody;
	physBodyDefs[aName]->position.Set(aPosX, aPosY);
}

b2Body* PhysicsManager::CreateDynamicBody(std::string aName, float aWidth, float aHeight, float aMass, float aFriction)
{
	if (physBodyDefs.find(aName) != physBodyDefs.end())
	{
		physBodies[aName] = world->CreateBody(physBodyDefs[aName]);
		physPolyShapes[aName] = new b2PolygonShape;
		physPolyShapes[aName]->SetAsBox(aWidth, aHeight);
		physFixtureDefs[aName] = new b2FixtureDef;
		physFixtureDefs[aName]->shape = physPolyShapes[aName];
		physFixtureDefs[aName]->density = aMass;
		physFixtureDefs[aName]->friction = aFriction;

		return physBodies[aName];
	}
	else
	{
		return nullptr;
	}
}

b2BodyDef* PhysicsManager::GetBodyDef(std::string aName)
{
	if (physBodyDefs.find(aName) != physBodyDefs.end())
	{
		return physBodyDefs.find(aName)->second;
	}
	else
	{
		return nullptr;
	}
}
