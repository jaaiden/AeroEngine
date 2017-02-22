#pragma once
#include <string>

class GameObject;

class Component
{
public:
	Component(GameObject* goParent);
	~Component();

	// Update logic
	virtual void Update();
	virtual void Render();

	GameObject* parent;

	//inline GameObject GetParent() { return *parent; }
	inline void SetParent(GameObject* goParent) { parent = goParent; }

	virtual void SendDataToJson(nlohmann::json &jsonFile);

private:
	static unsigned int mLastUniqueId;
	unsigned int mUniqueId;

	std::string mName;

	inline unsigned int GetUniqueId() { return mUniqueId; }
	inline unsigned int GetNextUniqueId() { return mLastUniqueId++; }
	inline std::string GetName() { return mName; }
	inline void SetName(std::string aName) { mName = aName; }
};

