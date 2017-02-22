#include "Renderable.h"
#include "Engine.h"


Renderable::Renderable()
{
	Engine::GetInstance()->AddRenderable(this);
}

Renderable::~Renderable()
{
	Engine::GetInstance()->RemoveRenderable(this);
}

void Renderable::Render()
{

}