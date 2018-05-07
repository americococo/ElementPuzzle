#include "GameBlock.h"
#include "Sprite.h"

#include "Map.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "BlockManager.h"

GameBlock::GameBlock() 
{
	_blocktype = eBlockType::GAMEBLOCK;
}
GameBlock::~GameBlock() {}
void GameBlock::Init() 
{
	_BlockImg = new Sprite(L"DefalufGameBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;

}
void GameBlock::Start()
{

}
void GameBlock::Update(float deltaTime)
{
	Map * map = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager()->GetMap();
	BlockManger * blockManger = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager();
	std::list<GameBlock*> blockList = blockManger->FindBlock(this);

	if (blockList.size() == 2)
	{
		if (map->CanMove(_posx + 1, _posy))
		{
			map->ResetTile(this, _posx, _posy);
			map->DestoryTile(_posx, _posy);
			_posx += 1;
			_posy += 0;
			map->SetBlock(this, _posx, _posy);
		}
	}


}
void GameBlock::Render() 
{
	_BlockImg->render();
}