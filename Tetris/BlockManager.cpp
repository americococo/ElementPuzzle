#include "BlockManager.h"
#include "GameSystem.h"
#include "Block.h"
#include "SelectBlock.h"
#include "GameBlock.h"

#include "Map.h"

BlockManger::BlockManger()
{
}

BlockManger::~BlockManger()
{
}

void BlockManger::Init()
{
	_map = new Map();
	_map->Init(15, 15);
	
}
void BlockManger::Update(float deltaTime)
{
	_map->Update(deltaTime);
	
	if ( GameSystem::GetInstance()->IsKeyDown(VK_SPACE) && _map->CanPutBlock()&& true== _blockIndex.empty())
	{
		Block * block = new SelectBlock();
		block->Init();
		int randPositionX = rand() % _map->GetSizeX();
		int randPositionY = rand() % _map->GetSizeY();

		do
		{
			randPositionX = rand() % _map->GetSizeX();
			randPositionY = rand() % _map->GetSizeY();
		} while (! _map->CanMove(randPositionX, randPositionY));

		_map->SetBlock(block, randPositionX, randPositionY);
		 
		_blockIndex.push(block);
	}

	if (!GameSystem::GetInstance()->IsKeyDown(VK_SPACE)&& false == _blockIndex.empty())
	{
		Block * block = _blockIndex.back();
		_blockIndex.pop();
		int changePosX = block->GetPosX();
		int changePosY = block->GetPosY();
		_map->ResetTile(block, changePosX, changePosY);
		_map->DestoryTile(changePosX, changePosY);
		delete block;

		block = new GameBlock();
		block->Init();
		
		_map->SetBlock(block, changePosX, changePosY);
		((GameBlock*)(block))->Start();
	}

}


void  BlockManger::Render()
{
	_map->Render();
}

std::list<GameBlock*> BlockManger::FindBlock(Block * finder)
{
	int MinTileX = finder->GetPosX() - 1;
	int MaxTileX = finder->GetPosX() + 1;

	int MinTileY = finder->GetPosY() - 1;
	int MaxTileY = finder->GetPosY() + 1;

	if (MinTileX < 0)
		MinTileX = 0;

	if (MaxTileX >= _map->GetSizeX())
		MaxTileX = _map->GetSizeX()-1;

	if (MinTileY < 0)
		MinTileY = 0;

	if (MaxTileY >= _map->GetSizeY())
		MaxTileY = _map->GetSizeY()-1;


	std::list<GameBlock*> _blockList;
	for (int y = MinTileY; y <= MaxTileY; y++)
	{
		for (int x = MinTileX; x <= MaxTileX; x++)
		{
			_map->GetBlockList(_blockList, x, y);
		}
	}
	return _blockList;
}