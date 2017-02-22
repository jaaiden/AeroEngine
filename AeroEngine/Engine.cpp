#include <iostream>
#include "Engine.h"

int Engine::mScreenWidth = 640;
int Engine::mScreenHeight = 480;
INIT_SINGLETON(Engine);

Engine::Engine():
	mInputMgr(),
	mGOManager(),
	mWindow(NULL),
	mWindowSurface(NULL),
	mGameObjectBitmap(NULL)
{

}

Engine::~Engine()
{
	// Free the game object bitmap
	SDL_FreeSurface(mGameObjectBitmap);
	mGameObjectBitmap = NULL;

	// Destroy the SDL windwow
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	// Quit SDL
	SDL_Quit();
}

void Engine::Init()
{
	// Initialization
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER))
	{
		std::cout << "Unable to initialize SDL " << SDL_GetError();
		return;
	}

	// Create the window
	mWindow = SDL_CreateWindow("AeroEngine",
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		mScreenWidth,                               // width, in pixels
		mScreenHeight,                               // height, in pixels
		SDL_WINDOW_RESIZABLE			   // flags - see below
	);

	// Load our test image
	/*
	mGameObjectBitmap = SDL_LoadBMP("resources/gameObject.bmp");
	if (mGameObjectBitmap == NULL)
	{
		std::cout << "Unable to load the bitmap file";
	}
	*/
	mWindowSurface = SDL_GetWindowSurface(mWindow);
}

void Engine::Run()
{
	// Main game loop
	SDL_Event pollEvent;
	bool quit = false;

	while (!quit)
	{
		// Input();
		//int SDL_PollEvent(SDL_Event* event)

		while (SDL_PollEvent(&pollEvent))
		{
			switch (pollEvent.type)
			{
				case SDL_EventType::SDL_QUIT:
					quit = true;
					break;
				case SDL_EventType::SDL_KEYDOWN:
					mInputMgr.ProcessInput(pollEvent.key.keysym.sym);
					break;
				case SDL_EventType::SDL_KEYUP:
					mInputMgr.ProcessInput(pollEvent.key.keysym.sym);
					break;
				case SDL_EventType::SDL_CONTROLLERDEVICEADDED:
					mInputMgr.AddGamePad(pollEvent.cdevice.which);
					break;
				case SDL_EventType::SDL_CONTROLLERDEVICEREMOVED:
					mInputMgr.RemoveGamePad(pollEvent.cdevice.which);
					break;
				case SDL_EventType::SDL_CONTROLLERBUTTONDOWN:
					mInputMgr.ProcessControllerInput(pollEvent.cbutton);
					break;
				case SDL_EventType::SDL_CONTROLLERBUTTONUP:
					mInputMgr.ProcessControllerInput(pollEvent.cbutton);
					break;
			}
		}

		// Update();
		// Allow our game programmers to run logic
		// Update our simulation:
		//  - Physics
		//  - Animation
		//  - Particles
		//  - Sound
		//  - ...and any other automated system...
		mGOManager.Update();

		// Render();
		// Blit the surface onto the screen
		/*
		SDL_Rect source;
		source.x = 0; // Position in the source surface
		source.y = 0;
		source.w = 64; // Size of the image
		source.h = 64;

		position.x++;
		position.y++;

		int isError = SDL_BlitSurface(mGameObjectBitmap, &source, mWindowSurface, &position);
		if (isError > 0)
		{
			std::cout << SDL_GetError() << std::endl;
		}
		*/

		// Tell everything that it should be rendering!
		// Loop through everything that needs to be rendering, telling it to be rendered.
		for (RenderableContainer::iterator itr = mRenderables.begin(); itr != mRenderables.end(); itr++)
		{
			(*itr)->Render();
		}

		SDL_UpdateWindowSurface(mWindow);
		//SDL_Delay(100);
	}

}

void Engine::AddRenderable(Renderable *aRenderable)
{
	mRenderables.push_back(aRenderable);
}

void Engine::RemoveRenderable(Renderable *aRenderable)
{
	
}