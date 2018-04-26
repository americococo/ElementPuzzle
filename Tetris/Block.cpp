#include "Block.h"
#include "Sprite.h"
#include "GameSystem.h"

#include "SceneManager.h"
#include "GameScene.h"

#include "Map.h"

#include <stdio.h>
Block::Block() {}
Block::~Block() {}

void Block::Init()
{
	_BlockImg = new Sprite(L"Block.png", L"Block.json");
	_BlockImg->Init();


	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();
	
}
void Block::Update(float deltaTime)
{
	_BlockImg->Update(deltaTime);
}

void Block::SetPosition(int posX, int posY)
{
	_RealPostionX = _Width / 2 + (_Width*posX);
	_RealPostionY = _Height / 2 + (_Height*posY);

 	_BlockImg->setPostition(_RealPostionX, _RealPostionY);

	_posx = posX;
	_posy = posY;
}
void Block::Render()
{
	_BlockImg->render();
}