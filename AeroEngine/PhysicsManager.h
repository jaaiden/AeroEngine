#pragma once
#include <Box2D\Box2D.h>
#include <string>
#include <map>
#include "Singleton.h"

class PhysicsManager : public Singleton<PhysicsManager>
{
public:
	PhysicsManager();
	~PhysicsManager() {}

	inline void Update(float deltaTime) { StepForward(deltaTime); }
	
	inline b2Vec2 GetGravity() { return gravity; }
	inline void SetGravity(b2Vec2 gravityFactor) { gravity = gravityFactor; }
	inline void SetGravity(float gravityX, float gravityY) { gravity = b2Vec2(gravityX, gravityY); }

	inline float GetTimestep() { return timestep; }
	inline void SetTimestep(float aTimestep) { timestep = aTimestep; }
	void StepForward(float stepAmount);

	// Ground functions
	inline b2BodyDef GetGroundBodyDef() { return physGroundDef; }
	inline b2Body* GetGroundBody() { return physGroundBody; }
	inline b2PolygonShape GetGroundShape() { return physGroundShape; }

	// World functions
	void AddBody(const b2BodyDef &aBodyDef, b2Body* &aBody);
	void CreateBoxFixture(b2PolygonShape &aPolyShape, float aWidth, float aHeight, b2Body* aBody, float aMass);
	void CreateBodyDef(std::string aName, float aPosX, float aPosY);
	b2Body* CreateDynamicBody(std::string aName, float aWidth, float aHeight, float aMass, float aFriction);
	b2BodyDef* GetBodyDef(std::string aName);

private:
	// Initialize default world variables
	b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
	std::unique_ptr<b2World> world;

	// Setup time, velocity, and position step factors
	float timestep = 1/60;
	int velocityIterator = 6;
	int positionIterator = 2;

	// Create container maps
	typedef std::map<std::string, b2BodyDef*> BodyDefContainer;
	typedef std::map<std::string, b2Body*> BodyContainer;
	typedef std::map<std::string, b2PolygonShape*> PolygonShapeContainer;
	typedef std::map<std::string, b2FixtureDef*> FixtureDefContainer;

	BodyDefContainer physBodyDefs;
	BodyContainer physBodies;
	PolygonShapeContainer physPolyShapes;
	FixtureDefContainer physFixtureDefs;

	// Create ground area
	b2BodyDef physGroundDef;
	b2Body* physGroundBody;
	b2PolygonShape physGroundShape;
};