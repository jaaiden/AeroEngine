#include <iostream>
#include <string>
#include "Engine.h"
#include "InputManager.h"
#include "Singleton.h"

INIT_SINGLETON(InputManager);

InputManager::InputManager()
{}

InputManager::~InputManager()
{}

void InputManager::CreateBind(SDL_Keycode aKey, std::string aName)
{
	// Add the bind to our bind mapping
	KeyBindMap::iterator itr = binds.find(aKey);
	if (itr != binds.end())
	{
		itr->second.push_back(aName);
	}
	else
	{
		binds[aKey].push_back(aName);
	}
}

void InputManager::ProcessInput(SDL_Keycode aKey)
{
	// Check all of our binds
	// if this keycode exists
	//    - call *all* of the callback functions
	KeyBindMap::const_iterator itr = binds.find(aKey);
	if (itr != binds.end())
	{
		// Loop over the named "Events" that are bound to this key
		for (int i = 0; i < itr->second.size(); i++)
		{
			// Function pointer logic using itr->second[i]
			//(*aCallback)();
			CallbackMap::iterator itr2 = callbacks.find(itr->second[i]);
			if (itr2 != callbacks.end())
			{
				// Loop through all of the callback functions
				for (int j = 0; j < itr2->second.size(); j++)
				{
					(*itr2->second[j])();
				}
			}
		}
	}
}

void InputManager::ProcessControllerInput(const SDL_ControllerButtonEvent aButton)
{
	std::cout << "Input detected on controller: " << aButton.button << std::endl;
}

void InputManager::AddCallback(std::string aEvent, InputCallback aCallback)
{
	CallbackMap::iterator itr = callbacks.find(aEvent);
	if (itr != callbacks.end())
	{
		itr->second.push_back(aCallback);
	}
	else
	{
		callbacks[aEvent].push_back(aCallback);
	}
}

void InputManager::AddGamePad(int aGamePadId)
{
	std::cout << "Detected peripheral connection..." << std::endl;
	if (SDL_IsGameController(aGamePadId))
	{
		std::cout << "Peripheral is a game controller." << std::endl;
		SDL_GameController *gamePad = SDL_GameControllerOpen(aGamePadId);

		if (gamePad)
		{
			SDL_Joystick *joystick = SDL_GameControllerGetJoystick(gamePad);
			int gpInstanceId = SDL_JoystickInstanceID(joystick);
			AddGamePadToList(aGamePadId, gamePad);
			std::cout << "Connected GamePad ID " << aGamePadId << std::endl;
		}
	}
}

void InputManager::RemoveGamePad(int aGamePadId)
{
	std::cout << "Disconnecting GamePad ID " << aGamePadId << std::endl;
	SDL_GameController *gamePad = GetGamePadFromList(aGamePadId);
	SDL_GameControllerClose(gamePad);
	RemoveGamePadFromList(aGamePadId);
	std::cout << "Disconnected GamePad ID " << aGamePadId << std::endl;
}

void InputManager::AddGamePadToList(int aGamePadId, SDL_GameController *aGamePad)
{
	gamePads[aGamePadId] = aGamePad;
}

SDL_GameController* InputManager::GetGamePadFromList(int aGamePadId)
{
	GamePadMap::iterator itr = gamePads.find(aGamePadId);
	if (itr != gamePads.end())
	{
		return itr->second;
	}
}

void InputManager::RemoveGamePadFromList(int aGamePadId)
{
	GamePadMap::iterator itr = gamePads.find(aGamePadId);
	if (itr != gamePads.end())
	{
		gamePads.erase(itr);
	}
}