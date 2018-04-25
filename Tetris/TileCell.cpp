#include "TileCell.h"
#include "GameSystem.h"
#include "Sprite.h"
#include "Block.h"
#include "BlankBlock.h"

TileCell::TileCell()
{
	{
		Block * block = new BlanBlock();
		block->Init();
		Tile.push_back(block);
	}

}
TileCell::~TileCell()
{

}
void TileCell::Init(int posX, int posY)
{
	_posX = posX;
	_posY = posY;

	std::list<Block*>::iterator itr;

	for (itr = Tile.begin(); itr != Tile.end(); itr++)
	{
		(*itr)->SetPosition(_posX, _posY);
	}
}

void TileCell::Update(float deltaTime)
{
	std::list<Block*>::iterator itr;
	for (itr = Tile.begin(); itr != Tile.end(); itr++)
	{
		(*itr)->Update(deltaTime);
	}
}

void TileCell::Render()
{
	std::list<Block*>::iterator itr;
	for (itr = Tile.begin(); itr != Tile.end(); itr++)
	{
		(*itr)->Render();
	}
}


void TileCell::SetBlock(Block * block)
{
	block->SetPosition(_posX, _posY);
	Tile.push_back(block);
}