#include "GameScene.h"


#include "GameSystem.h"
#include "SceneManager.h"

#include "BlockManager.h"

#include "Font.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Start()
{

	GameSystem::GetInstance()->InitInput();

	_blockManager = new BlockManger();
	_blockManager->Init();


	D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255);
	_font = new Font(L"Arial", 50, color);

	_score = 0;
}

void GameScene::Update(float deltaTime) 
{
	if (GameSystem::GetInstance()->IsKeyDown(VK_F1))
	{
		SceneManager::GetInstance()->ChangeScene(eScene::TITLE);
		return;
	}

	_blockManager->Update(deltaTime);


	WCHAR text[128];
	wsprintf(text, L"GAMESCORE: %d", _score);
	_font->setText(text);
}

void GameScene::GetScore(int score)
{
	_score += score;
}

void GameScene::Render() 
{
	_blockManager->Render();
	_font->SetAlia(DT_BOTTOM);
	_font->SetRect(0, GameSystem::GetInstance()->GetHeight() - 100, 500, 100);
	_font->render();
}
void GameScene::Stop()
{

}