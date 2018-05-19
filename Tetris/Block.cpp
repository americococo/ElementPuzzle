#include "Block.h"
#include "Sprite.h"
#include "GameSystem.h"

#include "SceneManager.h"
#include "GameScene.h"
#include "BlockManager.h"

#include "Map.h"

#include <stdio.h>

Block::Block() 
{
	_blocktype = eBlockType::NONEBLOCK;
}
Block::~Block() {}

void Block::Init()
{
	_BlockImg = new Sprite(L"Block.png");
	_BlockImg->Init();


	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();
	
	_isMovableTile = false;

}
void Block::Update(float deltaTime)
{
	
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
