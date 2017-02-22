#include "ComponentFactory.h"
#include "ImageComponent.h"
#include "AudioComponent.h"
#include "ScriptComponent.h"
#include "TransformComponent.h"

ComponentFactory::~ComponentFactory()
{}

Component * ComponentFactory::CreateComponent(const std::string &aCompType, GameObject* aGameObject)
{
	if (aCompType == "Image")
		return new ImageComponent(aGameObject);
	//else if (aCompType == "Audio")
		//return new AudioComponent();
	//else if (aCompType == "Script")
		//return new ScriptComponent();
	else if (aCompType == "Transform")
		return new TransformComponent(aGameObject);

	return 0;
}