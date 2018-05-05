#include "GameBlock.h"
#include "Sprite.h"

#include "Map.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "BlockManager.h"

GameBlock::GameBlock() {}
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
	int selx = (rand() % 3 + 1) - 2;
	int sely = (rand() % 3 + 1) - 2;

	Map * map = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager()->GetMap();
	if(map->CanMove(_posx + selx, _posy + sely))
	{
		map->ResetTile(this, _posx, _posy);
		map->SetBlock(this, _posx + selx, _posy + sely);
	}
}
void GameBlock::Update(float deltaTime)
{
}
void GameBlock::Render() 
{
	_BlockImg->render();
}