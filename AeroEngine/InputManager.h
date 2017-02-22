#include <SDL_keycode.h>
#include <SDL_events.h>
#include <string>
#include <map>
#include <vector>
#include "Singleton.h"
#pragma once

// Handles input
// - Gets notified when a user has pressed a key
// - Handles key -> "event" mapping
// - "Fire" off the game events
class InputManager : public Singleton<InputManager>
{
public:
	InputManager();
	~InputManager();

	// Create a new binding, mapping a SDL_Keycode to a named event
	void CreateBind(SDL_Keycode aKey, std::string aName);

	// Called externally when a keycode has been pressed
	void ProcessInput(SDL_Keycode aKey);

	// Called externally when a controller button has been pressed
	void ProcessControllerInput(const SDL_ControllerButtonEvent aButton);

	// Function pointer typedef
	typedef void(*InputCallback)();

	// Add a callback for when a specific event occurs
	void AddCallback(std::string aEvent, InputCallback aCallback);

	// Add game controller to engine
	void AddGamePad(int aGamePadId);

	// Remove game controller from engine
	void RemoveGamePad(int aGamePadId);

	// Add game controller to map
	void AddGamePadToList(int aGamePadId, SDL_GameController *aGamePad);

	// Retrieve a game controller from the map
	SDL_GameController* GetGamePadFromList(int aGamePadId);

	// Remove game controller from map
	void RemoveGamePadFromList(int aGamePadId);

private:
	// Binds
	// int -> [string]
	typedef std::map<SDL_Keycode, std::vector<std::string>> KeyBindMap;
	KeyBindMap binds;


	// Maps events like "Jump" to the specific functions that should be invoked when
	// the events happen
	typedef std::map<std::string, std::vector<InputCallback>> CallbackMap;
	CallbackMap callbacks;


	// Game Controller list
	typedef std::map<int, SDL_GameController*> GamePadMap;
	GamePadMap gamePads;
};

