#pragma once
#include <vector>
#include <map>
#include <list>
#include "Component.h"
#include "TransformComponent.h"

// Game Object class
class GameObject
{
public:
	typedef std::map<unsigned int, Component*> ComponentContainer;
	GameObject(std::string &aName);
	~GameObject();

	// GetComponent<type class>
	// Returns the component of the type class you want
	// Returns NULL if the component does not exist

	// Update
	void Update();
	void Render();

	template <class T>
	T* GetComponent();

	inline ComponentContainer GetComponents() { return mComponents; };

	void AddComponent(Component* comp);

	inline std::string GetName() { return mName; }
	inline void SetName(std::string aName) { mName = aName; }

	// Position data
	// Handled by TransformComponent
	TransformComponent* transform;
private:

	// Visuals (optional)
	// 

	// Name
	std::string mName;

	// Container of components
	ComponentContainer mComponents;
};

template<class T>
inline T * GameObject::GetComponent()
{
	for (auto &itr : mComponents)
	{
		if (dynamic_cast<T*>(itr.second) != 0)
		{
			return dynamic_cast<T*>(itr.second);
		}
	}
	return NULL;
}
