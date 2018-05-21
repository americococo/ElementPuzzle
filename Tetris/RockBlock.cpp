#include "RockBlock.h"

#include "Sprite.h"
#include "Map.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "BlockManager.h"

RockBlock::RockBlock()
{
	GameBlock::GameBlock();
	_Gameblocktype = eGameBlockType::ROCK;
}
RockBlock::~RockBlock() {}
void RockBlock::Init()
{
	_BlockImg = new Sprite(L"RockBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;

	_lifePoint = 1;
}
void RockBlock::Start()
{
	Map * map = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager()->GetMap();
	BlockManger * blockManger = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager();

	std::list<GameBlock*> blockList = blockManger->FindBlock(this, 1);

	int MinTileX = _posx - 1;
	int MaxTileX = _posx + 1;

	int MinTileY = _posy- 1;
	int MaxTileY = _posy + 1;

	if (MinTileX < 0)
		MinTileX = 0;

	if (MaxTileX >= map->GetSizeX())
		MaxTileX = map->GetSizeX() - 1;

	if (MinTileY < 0)
		MinTileY = 0;

	if (MaxTileY >= map->GetSizeY())
		MaxTileY = map->GetSizeY() - 1;



	for (int y = MinTileY; y <= MaxTileY; y++)
	{
		if (map->CanMove(_posx, y))
		{
			Block * block = new GameBlock();
			block->Init();
			map->SetBlock(block, _posx, y);
			((GameBlock*)(block))->Start();
		}
	}
	for (int x = MinTileX; x <= MaxTileX; x++)
	{
		if (map->CanMove(x, _posy))
		{
			Block * block = new GameBlock();
			block->Init();
			map->SetBlock(block, x, _posy);
			((GameBlock*)(block))->Start();
		}
	}
}
void RockBlock::Update(float deltaTime)
{
	GameBlock::Update(deltaTime);





}
void RockBlock::Render()
{
	_BlockImg->render();
}