#pragma once
#include <List>
#include "GameObject.h"
#include "Singleton.h"
#include "Json.h"

class GOManager : public Singleton<GOManager>
{
public:
	GOManager();
	~GOManager();

	// Update all of the game objects
	void Update();
	void Render();

	void AddGameObject(nlohmann::json &aJsonData);

	GameObject GetGameObject(int index);

	void CreateGameObjectFile(GameObject* aGameObject);

private:
	// All of the game objects in our simulation
	typedef std::list<GameObject> GOContainer;
	GOContainer gameObjects;
};

