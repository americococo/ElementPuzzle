#include "TitleScene.h"
#include "GameSystem.h"
#include "Sprite.h"

#include "SceneManager.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Start()
{
	GameSystem::GetInstance()->InitInput();
	_backGround = new Sprite(L"_ba1.png", L"BackGround.json");
	_backGround->Init();
	_backGround->setPostition(GameSystem::GetInstance()->GetWidth() / 2, GameSystem::GetInstance()->GetHeight() / 2);
}
void TitleScene::Update(float deltaTime)
{
	if (GameSystem::GetInstance()->IsKeyDown(VK_SPACE))
	{
		SceneManager::GetInstance()->ChangeScene(eScene::GAME);
		return;
	}
	_backGround->Update(deltaTime);

}
void TitleScene::Render()
{
	_backGround->render();
}
void TitleScene::Stop()
{
	if (_backGround != nullptr)
	{
		_backGround->deInit();
		delete _backGround;
	}
	_backGround = nullptr;
}