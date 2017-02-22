#pragma once
#include <string>
#include "Component.h"

class PhysicsComponent : public Component
{
public:
	PhysicsComponent(GameObject* goParent);
	~PhysicsComponent() {}

	inline float GetWidth() { return mWidth; }
	inline void SetWidth(float aWidth) { mWidth = aWidth; }

	inline float GetHeight() { return mHeight; }
	inline void SetHeight(float aHeight) { mHeight = aHeight; }

	void Update();

private:
	float mWidth;
	float mHeight;
	b2Body* physBody;
};