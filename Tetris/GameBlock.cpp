#include "GameBlock.h"
#include "Sprite.h"

#include "Map.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "BlockManager.h"

GameBlock::GameBlock() 
{
	_blocktype = eBlockType::GAMEBLOCK;
	_Gameblocktype = eGameBlockType::DefaultBlock;
}
GameBlock::~GameBlock() {}
void GameBlock::Init() 
{
	_BlockImg = new Sprite(L"DefalufGameBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;

	_lifePoint = 1;
}
void GameBlock::Start()
{

}
void GameBlock::Update(float deltaTime)
{
	lifeCheck();
}

void GameBlock::lifeCheck()
{
	GameScene * scene = (GameScene*)SceneManager::GetInstance()->GetScene();
	Map * map = scene->GetBlockManager()->GetMap();

	if (_lifePoint <= 0)
	{
		map->ResetTile(this, this->GetPosX(), this->GetPosY());
		map->DestoryTile(this->GetPosX(), this->GetPosY());
		map->RemoveBlock(this, this->GetPosX(), this->GetPosY());

		scene->GetScore(5);
	}
}

void GameBlock::Render() 
{
	_BlockImg->render();
}