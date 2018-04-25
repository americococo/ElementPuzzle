#include "GameScene.h"
#include "Block.h"

#include "GameSystem.h"
#include "SceneManager.h"
#include "Map.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Start()
{

	GameSystem::GetInstance()->InitInput();

	_map = new Map();
	_map->Init(10, 10);

}

void GameScene::Update(float deltaTime) 
{
	if (GameSystem::GetInstance()->IsKeyDown(VK_F1))
	{
		SceneManager::GetInstance()->ChangeScene(eScene::TITLE);
		return;
	}

	_map->Update(deltaTime);

	if (GameSystem::GetInstance()->IsKeyDown(VK_SPACE))
	{
		int randX = rand() % 10;
		int randY = rand() % 10;
		if (_map->CanMove(rand() % 10, rand() % 10))
		{
			Block * block = new Block();
			block->Init();
			_map->SetBlock(block, randX, randY);
		}
	}
}
void GameScene::Render() 
{
	_map->Render();
}
void GameScene::Stop()
{
	delete _map;
}