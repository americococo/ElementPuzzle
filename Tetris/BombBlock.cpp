#include "BombBlock.h"
#include "Sprite.h"

#include "Map.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "BlockManager.h"

BombBlock::BombBlock()
{
	GameBlock::GameBlock();
	_Gameblocktype = eGameBlockType::BOMBBLOCK;
}
BombBlock::~BombBlock() {}

void BombBlock::Init()
{
	_BlockImg = new Sprite(L"BombGameBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;

}
void BombBlock::Start()
{


}
void BombBlock::Update(float deltaTime)
{
	GameScene * scene = (GameScene*)SceneManager::GetInstance()->GetScene();
	Map * map = scene->GetBlockManager()->GetMap();
	BlockManger * blockManger = scene->GetBlockManager();

	std::list<GameBlock*> blockList = blockManger->FindBlock(this,2);

	std::list<GameBlock*>::iterator itr;

	if (blockList.size() >= 5)
	{
		for (itr = blockList.begin(); itr != blockList.end(); itr++)
		{
			map->ResetTile((*itr), (*itr)->GetPosX(), (*itr)->GetPosY());
			map->DestoryTile((*itr)->GetPosX(), (*itr)->GetPosY());
			map->RemoveBlock((*itr), (*itr)->GetPosX(), (*itr)->GetPosY());

			scene->GetScore(5);
		}
	}
}
void BombBlock::Render()
{
	_BlockImg->render();
}