#include <iostream>
#include <fstream>
#include "GOManager.h"
#include "Singleton.h"
#include "ComponentFactory.h"
#include "Json.h"

INIT_SINGLETON(GOManager);

GOManager::GOManager()
{
}


GOManager::~GOManager()
{
}

void GOManager::Update()
{
	//std::cout << "GOManager::Update" << std::endl;
	for (GOContainer::iterator itr = gameObjects.begin(); itr != gameObjects.end(); itr++)
	{
		itr->Update();
	}
}

void GOManager::Render()
{
	//std::cout << "GOManager::Update" << std::endl;
	for (GOContainer::iterator itr = gameObjects.begin(); itr != gameObjects.end(); itr++)
	{
		itr->Render();
	}
}

void GOManager::AddGameObject(nlohmann::json &aJsonData)
{
	//std::string name = "TestObj";
	GameObject* go = new GameObject(aJsonData["name"]);

	ComponentFactory cFact;
	Component *newComp = cFact.CreateComponent(aJsonData["type"], go);
	go->AddComponent(newComp);

	gameObjects.push_back(*go);
}

GameObject GOManager::GetGameObject(int index)
{
	GOContainer::iterator itr = gameObjects.begin();
	std::advance(itr, index);
	return *itr;
}

void GOManager::CreateGameObjectFile(GameObject * aGameObject)
{
	nlohmann::json goFile;
	goFile["name"] = aGameObject->GetName();
	goFile["components"] = {};
	GameObject::ComponentContainer goComponents = aGameObject->GetComponents();

	for (GameObject::ComponentContainer::iterator itr = goComponents.begin(); itr != goComponents.end(); itr++)
	{
		itr->second->SendDataToJson(goFile);
	}

	std::cout << "Creating player gameobject prefab..." << std::endl;
	std::ofstream out("gamefiles/gameobjects/player.json");
	std::cout << "done." << std::endl;
	out << goFile.dump();
	out.close();
}