#pragma once

#include <vector>
#include <SDL.h>
#include <SDL_video.h>
#include "InputManager.h"
#include "GOManager.h"
#include "Singleton.h"
#include "Renderable.h"

class Engine : public Singleton<Engine>
{
public:
	Engine();
	~Engine();

	// Initialize the engine
	void Init();

	// Run the engine
	void Run();

	static int mScreenWidth;
	static int mScreenHeight;

	// Keep track of renderable object
	void AddRenderable(Renderable *aRenderable);
	void RemoveRenderable(Renderable *aRenderable);

	inline SDL_Surface* GetWindowSurface() { return mWindowSurface; }

private:

	// SDL Window
	SDL_Window *mWindow;
	SDL_Surface *mWindowSurface;
	SDL_Surface *mGameObjectBitmap;

	// Other engine singleton classes
	InputManager mInputMgr;
	GOManager mGOManager;

	typedef std::vector<Renderable*> RenderableContainer;
	RenderableContainer mRenderables;
};
