#include "BlockManager.h"
#include "GameSystem.h"
#include "Block.h"
#include "BombBlock.h"
#include "SelectBlock.h"
#include "GameBlock.h"
#include "ArrowMove.h"
#include "TeleportBlock.h"
#include "RockBlock.h"
#include "Map.h"

#include "Font.h"

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
	
	

	D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255);
	_font = new Font(L"Arial", 50, color);
}
void BlockManger::Update(float deltaTime)
{
	_map->Update(deltaTime);
	
	int density=  _map->Density();

	WCHAR text[128];
	wsprintf(text, L"¹ÐÁýµµ: %d %%", density);
	_font->setText(text);

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

		int blockType = rand() % eGameBlockType::NONE;

		switch ((eGameBlockType)blockType)
		{
		case eGameBlockType::DefaultBlock:
			block = new GameBlock();
			break;
		case eGameBlockType::BOMBBLOCK:
			block = new BombBlock();
			break;
		case eGameBlockType::ARROWMOVEBLOCK:
			block = new ArrowMoveBlock();
			break;
		case eGameBlockType::TELEPORT:
			block = new TeleportBlock();
			break;
		case eGameBlockType::ROCK:
			block = new RockBlock();
			break;
		}

		block->Init();
		_map->SetBlock(block, changePosX, changePosY);
		((GameBlock*)(block))->Start();
	}

}


void  BlockManger::Render()
{
	_map->Render();
	_font->SetAlia(DT_RIGHT | DT_BOTTOM);
	_font->SetRect(0, GameSystem::GetInstance()->GetHeight() - 100, GameSystem::GetInstance()->GetWidth() , 100);
	_font->render();
}

std::list<GameBlock*> BlockManger::FindBlock(Block * finder,int range)
{
	int MinTileX = finder->GetPosX() - range;
	int MaxTileX = finder->GetPosX() + range;

	int MinTileY = finder->GetPosY() - range;
	int MaxTileY = finder->GetPosY() + range;

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
		_map->GetBlockList(_blockList, finder->GetPosX(), y);
	}

	for (int x = MinTileX; x <= MaxTileX; x++)
	{
		if (finder->GetPosX() == x)
			continue;
		_map->GetBlockList(_blockList, x, finder->GetPosY());
	}

	return _blockList;
}