#include "BlockManager.h"
#include "GameSystem.h"
#include "Block.h"
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

}
void BlockManger::Update(float deltaTime)
{
	_map->Update(deltaTime);
	if (GameSystem::GetInstance()->IsKeyDown(VK_SPACE) && true == _isInstallBlock)
	{
		_isInstallBlock = false;

		RandSpwan();
	}
	if (false == _blockSelect.empty())
	{
		Block * block  = _blockSelect.back();
		int posx= block->GetPosX();
		int posy= block->GetPosY();

		int x = posx;
		int y = posy;

		if (GameSystem::GetInstance()->IsKeyDown(VK_LEFT))
			x--;
		if (GameSystem::GetInstance()->IsKeyDown(VK_RIGHT))
			x++;
		if (GameSystem::GetInstance()->IsKeyDown(VK_UP))
			y--;
		if (GameSystem::GetInstance()->IsKeyDown(VK_DOWN))
			y++;

		if (_map->CanMove(x, y))
		{
			_map->ResetTile(block, posx, posy);
			_map->SetBlock(block, x, y);
		}
	}
}
void BlockManger::RandSpwan()
{
	int randposX = rand() % 10;
	int randposY = rand() % 10;
	if (_map->CanMove(randposX, randposY))
	{
		Block * block = new Block();
		block->Init();
		_map->SetBlock(block, randposX, randposY);
		_blockSelect.push(block);
	}
}
void  BlockManger::Render()
{
	_map->Render();
}