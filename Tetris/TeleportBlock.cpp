#include "TeleportBlock.h"

#include "Sprite.h"


#include "Map.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "BlockManager.h"

TeleportBlock::TeleportBlock() 
{
	GameBlock::GameBlock();
	_Gameblocktype = eGameBlockType::TELEPORT;
}
TeleportBlock::~TeleportBlock() {}

void TeleportBlock::Init()
{
	_BlockImg = new Sprite(L"TeleportBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;

	_lifePoint = 1;
}
void TeleportBlock::Start()
{


}
void TeleportBlock::Update(float deltaTime)
{
	GameBlock::Update(deltaTime);


	Map * map = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager()->GetMap();
	BlockManger * blockManger = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager();

	std::list<GameBlock*> blockList = blockManger->FindBlock(this, 1);

	if (blockList.size() >=1)
	{
		for (std::list<GameBlock*>::iterator itr = blockList.begin(); itr != blockList.end(); itr++)
		{
			if ((*itr) == this)
				continue;

			{
				int posx = (*itr)->GetPosX();
				int posy = (*itr)->GetPosY();
				map->ResetTile((*itr), posx, posy);
				map->DestoryTile(posx, posy);

				do
				{
					posx = rand() % map->GetSizeX();
					posy = rand() % map->GetSizeY();
				} while (!map->CanMove(posx, posy));


				map->SetBlock((*itr), posx, posy);
			}
		}

	}

}
void TeleportBlock::Render()
{
	_BlockImg->render();
}