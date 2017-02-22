#include <vector>
#include <iostream>
#include <fstream>
#include "InputManager.h"
#include "GOManager.h"
#include "GameObject.h"
#include "Json.h"
#include "Engine.h"

// Component includes
#include "PlayerController.h"
#include "ImageComponent.h"
#include "AIController.h"

#undef main

void MoveLeft()
{
	std::cout << "MoveLeft()" << std::endl;
	GOManager::GetInstance()->GetGameObject(0).transform->SetMoveDirection(MoveDirection::LEFT);
}

void MoveRight()
{
	std::cout << "MoveRight()" << std::endl;
	GOManager::GetInstance()->GetGameObject(0).transform->SetMoveDirection(MoveDirection::RIGHT);
}

int main(int argc, char* argv[])
{
	/*
	// Serialization example
	nlohmann::json goFile;
	goFile["name"] = "Player";
	goFile["components"] = {
		{"Transform", {"position", {1, 1}}, {"rotation", {0, 0}}, {"scale", {128, 128} } }
	};
	std::cout << "Creating player gameobject prefab..." << std::endl;
	std::ofstream out("gamefiles/gameobjects/player.json");
	std::cout << "done." << std::endl;
	out << goFile.dump();
	out.close();
	*/

	// Deserialization
	nlohmann::json jsonData;
	std::ifstream in("gamefiles/gameobjects/player.json");
	jsonData = nlohmann::json::parse(in);
	
	//Engine::mScreenHeight = 100;
	
	// Get the instance of the engine
	Engine* myEngine = Engine::GetInstance();

	/* -- Old GameObject Creation Code --

	// Create the player GameObject
	GameObject* player = new GameObject(std::string("Player GameObject"));
	PlayerController* plyComp = new PlayerController(player);

	ImageComponent* imgComp = new ImageComponent(player);
	imgComp->LoadImage("resources/gameObject.bmp");

	player->AddComponent(plyComp);
	player->AddComponent(imgComp);

	// Create the AI GameObject
	GameObject* aiPlayer = new GameObject(std::string("AI GameObject"));
	aiPlayer->transform->position = Vector2(200, 200);
	AIController* aiComp = new AIController(aiPlayer);
	ImageComponent* aiImgComp = new ImageComponent(aiPlayer);
	aiImgComp->LoadImage("resources/aiGameObject.bmp");
	aiPlayer->AddComponent(aiComp);
	aiPlayer->AddComponent(aiImgComp);
	
	// Instanciate the GameObjects
	GOManager::GetInstance()->AddGameObject(player);
	GOManager::GetInstance()->AddGameObject(aiPlayer);

	*/

	//GOManager::GetInstance()->AddGameObject(jsonData);

	// Create default keybinds
	InputManager::GetInstance()->CreateBind(SDLK_a, "MoveLeft");
	InputManager::GetInstance()->CreateBind(SDLK_d, "MoveRight");
	InputManager::GetInstance()->CreateBind(SDLK_LEFT, "MoveLeft");
	InputManager::GetInstance()->CreateBind(SDLK_RIGHT, "MoveRight");

	// Set keybinds to function callback references
	InputManager::GetInstance()->AddCallback("MoveLeft", &MoveLeft);
	InputManager::GetInstance()->AddCallback("MoveRight", &MoveRight);

	myEngine->Init();
	myEngine->Run();

	return 0;
}