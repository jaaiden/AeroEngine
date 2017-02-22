#include <iostream>
#include "ImageComponent.h"
#include "Engine.h"

ImageComponent::ImageComponent(GameObject* goParent) : Component(goParent), Renderable()
{}

ImageComponent::~ImageComponent()
{}

bool ImageComponent::LoadImage(std::string aFileName)
{
	mFileName = aFileName;

	// Load our test image
	mImageSurface = SDL_LoadBMP(mFileName.c_str());
	if (mImageSurface == NULL)
	{
		std::cout << "Unable to load the bitmap file " << mFileName << std::endl;
		return false;
	}

	std::cout << "Loaded bitmap file: " << mFileName << std::endl;

	return true;
}

void ImageComponent::Render()
{
	SDL_Rect source;
	source.x = 0; // Position in the source surface
	source.y = 0;
	source.w = parent->transform->scale.x; // Size of the image
	source.h = parent->transform->scale.y;
	
	SDL_Rect position;
	position.x = parent->transform->position.x;
	position.y = parent->transform->position.y;

	int isError = SDL_BlitSurface(mImageSurface, &source, Engine::GetInstance()->GetWindowSurface(), &position);
	//std::cout << source.w << " " << source.h << std::endl;
	//std::cout << position.x << " " << position.y << std::endl;
	if (isError > 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}
