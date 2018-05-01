#include "GameBlock.h"
#include "Sprite.h"

GameBlock::GameBlock() {}
GameBlock::~GameBlock() {}
void GameBlock::Init() 
{
	_BlockImg = new Sprite(L"DefalufGameBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;
}
void GameBlock::Update(float deltaTime) {}
void GameBlock::Render() 
{
	_BlockImg->render();
}