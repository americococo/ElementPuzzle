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

	_lifePoint = 1;
}
void BombBlock::Start()
{


}
void BombBlock::Update(float deltaTime)
{
	GameBlock::Update(deltaTime);

	Map * map = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager()->GetMap();
	BlockManger * blockManger = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager();

	//queue
	//questStart(탐색시작) =  map->GetTileCell(_posx, _posy);
	//for(4Direction)
	//position nextTilecell_postition = questStart->nextTilecell(direction);
	//Tilecell *  nextTilecell = map->getTileCell(nextTilecell_postition )
	//canmove? -> nextTilecell_postition  && questMark(검사했었음) ? -> nextTilecell
	//queu.push(nextTilecell);
	//

	std::list<GameBlock*> blockList = blockManger->FindBlock(this, 3);

	if (blockList.size() >= 3)
	{
		for (std::list<GameBlock*>::iterator itr = blockList.begin(); itr != blockList.end(); itr++)
		{
			(*itr)->DecressLifePoint();

		}
	}
}
void BombBlock::Render()
{
	_BlockImg->render();
}