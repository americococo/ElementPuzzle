#include "BlankBlock.h"
#include "Sprite.h"

BlanBlock::BlanBlock()
{
}

BlanBlock::~BlanBlock()
{
}

void BlanBlock::Init()
{
	_BlockImg = new Sprite(L"BlankBlock.png", L"BlankBlock.json");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = true;
}

void BlanBlock::Update(float deltaTime)
{
	_BlockImg->Update(deltaTime);
}
void BlanBlock::Render()
{
	_BlockImg->render();
}