#pragma once
#include <string>
#include <SDL.h>
#include <SDL_video.h>
#include "Component.h"
#include "Renderable.h"

class ImageComponent :
	public Component,
	public Renderable
{
public:
	ImageComponent(GameObject* goParent);
	~ImageComponent();

	// Load a BMP file
	bool LoadImage(std::string aFileName);

	void Render();

private:
	// Name of the image file, with path
	std::string mFileName;

	// SDL Surface data for the loaded bmp file
	SDL_Surface *mImageSurface;
};

