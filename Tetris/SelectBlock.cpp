#include "SelectBlock.h"
#include "Sprite.h"

#include "GameSystem.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "BlockManager.h"
#include "Map.h"
#include <Windows.h>

#include "Font.h"
SelectBlock::SelectBlock() 
{
	_blocktype = eBlockType::NONEBLOCK;
}
SelectBlock::~SelectBlock()
{
	
}

void SelectBlock::Init()
{
	_BlockImg = new Sprite(L"SelectBlock.png");
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;

}
void SelectBlock::Update(float deltaTime)
{
	int posx = _posx;
	int posy = _posy;

	int x = 0;
	int y = 0;

	if (GameSystem::GetInstance()->isInputArrowLeft())
		x--;
	else if (GameSystem::GetInstance()->isInputArrowRight())
		x++;
	else if (GameSystem::GetInstance()->isInputArrowUp())
		y--;
	else if (GameSystem::GetInstance()->isInputArrowDown())
		y++;

	Map * map = ((GameScene*)SceneManager::GetInstance()->GetScene())->GetBlockManager()->GetMap();

	while (map->CanMove(posx + x, posy+ y))
	{
		map->ResetTile(this, posx, posy);
		map->DestoryTile(posx, posy);
		map->SetBlock(this, posx+x, posy+y);
		posx += x;
		posy += y;
	}

}

void SelectBlock::Render()
{
	_BlockImg->render();

}