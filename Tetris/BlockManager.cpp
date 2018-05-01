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
	_isInstallBlock = true;
	_map = new Map();
	_map->Init(10, 10);

	{
		GameBlock * block = new GameBlock();
		_BlockInformationList[eGameBlockType::DefaultBlock] = block;
	}
	
}
void BlockManger::Update(float deltaTime)
{
	_map->Update(deltaTime);
	
	if ( (!GameSystem::GetInstance()->IsKeyDown(VK_SPACE)) && true == _isInstallBlock && _map->CanPutBlock())
	{
		_isInstallBlock = false;

		RandSpwan();
	}
	if (false == _blockSelect.empty())
	{
		Block * block  = _blockSelect.back();
		int posx= block->GetPosX();
		int posy= block->GetPosY();

		int x = 0;
		int y = 0;

		//INput Direction
		switch (GameSystem::GetInstance()->isInputKey())
		{
		case VK_LEFT: x--;
			break;
		case VK_RIGHT: x++;
			break;
		case VK_UP: y--;
			break;
		case VK_DOWN: y++;
			break;
		}

		while(_map->CanMove(posx + x, posy + y))
		{
			_map->ResetTile(block, posx, posy);
			_map->SetBlock(block, posx + x, posy + y);
			posx = posx + x;
			posy = posy + y;
		}
	}

	if (GameSystem::GetInstance()->IsKeyDown(VK_SPACE))
	{
		_isInstallBlock = true;

		this->MakeGameBlock();
	}
}
void BlockManger::MakeGameBlock()
{
	if (false == _blockSelect.empty())
	{
		//delete
		Block * block = _blockSelect.back();
		int ChangePosX = block->GetPosX();
		int ChangePosY = block->GetPosY();
		_map->ResetTile(block, ChangePosX, ChangePosY);
		delete block;


		//making
		block = new GameBlock();
		block->Init();
		_map->SetBlock(block, ChangePosX, ChangePosY);
		_blockSelect.pop();
	}
}
void BlockManger::RandSpwan()
{
	int randposX = rand() % 10;
	int randposY = rand() % 10;


	do
	{
		randposX = rand() % 10;
		randposY = rand() % 10;
	} while (!(_map->CanMove(randposX, randposY)));


	{
		Block * block = new SelectBlock();
		block->Init();
		_map->SetBlock(block, randposX, randposY);
		_blockSelect.push(block);
	}

}
void  BlockManger::Render()
{
	_map->Render();
}

std::list<Block*> BlockManger::FindBlock(Block * finder)
{
	int MinTileX = finder->GetPosX() - 1;
	int MaxTileX = finder->GetPosX() + 1;

	int MinTileY = finder->GetPosY() - 1;
	int MaxTileY = finder->GetPosY() + 1;

	if (MinTileX < 0)
		MinTileX = 0;

	if (MaxTileX >= 10)
		MaxTileX = 10 - 1;

	if (MinTileY < 0)
		MinTileY = 0;

	if (MaxTileY >=10)
		MaxTileY = 10-1;


	std::list<Block*> _blockList;
	for (int y = MinTileY; y <= MaxTileY; y++)
	{
		for (int x = MinTileX; x <= MaxTileX; x++)
		{
			_map->GetBlockList(_blockList, x, y);
		}
	}
	return _blockList;
}