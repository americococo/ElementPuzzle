#include "TileCell.h"
#include "GameSystem.h"
#include "Sprite.h"
#include "Block.h"
#include "BlankBlock.h"
#include "GameBlock.h"
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
void TileCell::ReSetTile(Block * block)
{
	_deleteBlock.push(block);
}

void TileCell::DestoryBlock()
{
	if (false == _deleteBlock.empty())
	{
		Tile.remove(_deleteBlock.back());
		_deleteBlock.pop();

	}
}
void TileCell::Update(float deltaTime)
{
	std::list<Block*>::iterator itr;

	DestoryBlock();

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

bool TileCell::CanMove()
{
	std::list<Block*>::iterator itr;
	for (itr = Tile.begin(); itr != Tile.end(); itr++)
	{
		if (((*itr)->CanMove()) == false)
			return false;
	}
	return true;
}



void TileCell::SetBlock(Block * block)
{
	block->SetPosition(_posX, _posY);
	Tile.push_back(block);
}
void TileCell::GetBlockList(std::list<GameBlock*>& blockList) 
{
	for (std::list<Block*>::iterator itr = Tile.begin(); itr != Tile.end(); itr++)
	{
		if (false == (*itr)->CanMove()&&(*itr)->GetBlockType() == eBlockType::GAMEBLOCK)
		{
			GameBlock * block = (GameBlock*)(*itr);
			blockList.push_back(block);
		}
	}
}