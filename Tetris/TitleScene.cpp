#include "TitleScene.h"
#include "GameSystem.h"
#include "Sprite.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}
void TitleScene::Init()
{
	_backGround = new Sprite(L"_ba1.png",L"BackGround.json");
	_backGround->Init();
	_backGround->setPostition(GameSystem::GetInstance()->GetWidth() / 2, GameSystem::GetInstance()->GetHeight() / 2);
}
void TitleScene::Update(float deltaTime)
{
	_backGround->Update(deltaTime);
}
void TitleScene::Render()
{
	_backGround->render();
}
