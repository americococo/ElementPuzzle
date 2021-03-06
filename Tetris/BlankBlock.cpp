#include "BlankBlock.h"
#include "Sprite.h"

BlanBlock::BlanBlock()
{
	_blocktype = eBlockType::NONEBLOCK;
}

BlanBlock::~BlanBlock()
{
}

void BlanBlock::Init()
{
	_BlockImg = new Sprite(L"BlankBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = true;
}

void BlanBlock::Update(float deltaTime)
{
	
}
void BlanBlock::Render()
{
	_BlockImg->render();
}