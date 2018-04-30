#include <stdio.h>

#include "ResourceManager.h"


ResourceManager  * ResourceManager::Instance = NULL;

ResourceManager::ResourceManager()
{
	
}

ResourceManager::~ResourceManager()
{

}

ResourceManager * ResourceManager::GetInstance()
{
	if (Instance == NULL)
		Instance = new ResourceManager();

	return Instance;
}

Texture * ResourceManager::LoadTexture(std::wstring  spriteFileName)
{
	std::map<std::wstring, Texture*>::iterator itr = _textureMap.find(spriteFileName);
	if (itr != _textureMap.end())
	{
		return itr->second;
	}


	Texture * texture = new Texture();
	texture->Init(spriteFileName.c_str());

	_textureMap[spriteFileName] = texture;
	return texture;
		
}
