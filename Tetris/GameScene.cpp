#include "GameScene.h"
#include "Block.h"

#include "GameSystem.h"
#include "SceneManager.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Start()
{
	GameSystem::GetInstance()->InitInput();
	_block = new Block();
	_block->Init();
}

void GameScene::Update(float deltaTime) 
{
	if (GameSystem::GetInstance()->IsKeyDown(VK_F1))
	{
		SceneManager::GetInstance()->ChangeScene(eScene::TITLE);
		return;
	}
	_block->Update(deltaTime);
}
void GameScene::Render() 
{
	_block->Render();
}
void GameScene::Stop()
{
	delete _block;
}