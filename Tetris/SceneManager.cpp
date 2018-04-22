#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
SceneManager::SceneManager(){}
SceneManager::~SceneManager(){}
SceneManager* SceneManager::_instance = nullptr;
SceneManager * SceneManager::GetInstance()
{
	if (_instance == nullptr)
		_instance = new SceneManager();
	return _instance;
}

void SceneManager::ChangeScene(eScene type)
{
	if (_scene != nullptr)
	{
		_scene->Stop();
	}
	_scene = _sceneMap[type];
	_scene->Start();

}
void SceneManager::Update(float deltaTime)
{
	_scene->Update(deltaTime);
}
void SceneManager::Render()
{
	_scene->Render();
}
void SceneManager::InitScene()
{
	_scene = nullptr;
	{
		Scene * scene =new TitleScene();
		scene->Init();
		_sceneMap[eScene::TITLE] = scene;
	}
	ChangeScene(eScene::TITLE);
}