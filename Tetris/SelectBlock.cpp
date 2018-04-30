#include "SelectBlock.h"
#include "Sprite.h"
SelectBlock::SelectBlock() {}
SelectBlock::~SelectBlock() {}

void SelectBlock::Init()
{
	_BlockImg = new Sprite(L"SelectBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;
}
void SelectBlock::Update(float deltaTime)
{
//	_BlockImg->Update(deltaTime);
}
void SelectBlock::Render()
{
	_BlockImg->render();
}