#include "GameScene.h"


#include "GameSystem.h"
#include "SceneManager.h"

#include "BlockManager.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Start()
{

	GameSystem::GetInstance()->InitInput();

	

	_blockManager = new BlockManger();
	_blockManager->Init();
}

void GameScene::Update(float deltaTime) 
{
	if (GameSystem::GetInstance()->IsKeyDown(VK_F1))
	{
		SceneManager::GetInstance()->ChangeScene(eScene::TITLE);
		return;
	}

	_blockManager->Update(deltaTime);

}
void GameScene::Render() 
{
	_blockManager->Render();
}
void GameScene::Stop()
{

}