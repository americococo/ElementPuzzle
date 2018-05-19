#include "ArrowMove.h"
#include "Sprite.h"
#include "GameScene.h"
#include "Map.h"
#include "SceneManager.h"
#include "BlockManager.h"

ArrowMoveBlock::ArrowMoveBlock()
{
	GameBlock::GameBlock();
	_Gameblocktype = eGameBlockType::ARROWMOVEBLOCK;
}
ArrowMoveBlock::~ArrowMoveBlock() {}

void ArrowMoveBlock::Init()
{
	_direction = (eDirection)(rand() %( eDirection::DOWN + 1));


	switch (_direction)
	{
	case LEFT:
		_BlockImg = new Sprite(L"LeftArrowBlock.png");
		break;
	case RIGHT:
		_BlockImg = new Sprite(L"RightArrowBlock.png");
		break;
	case UP:
		_BlockImg = new Sprite(L"UpArrowBlock.png");
		break;
	case DOWN:
		_BlockImg = new Sprite(L"DownArrowBlock.png");
		break;
	}
	
	
	_BlockImg->Init();

	_Width = _BlockImg->GetWidth();
	_Height = _BlockImg->GetHeight();

	_isMovableTile = false;

	_lifePoint = 1;
}
void ArrowMoveBlock::Start()
{


}
void ArrowMoveBlock::Update(float deltaTime)
{
	GameBlock::Update(deltaTime);

	GameScene * scene = (GameScene*)SceneManager::GetInstance()->GetScene();
	Map * map = scene->GetBlockManager()->GetMap();
	BlockManger * blockManger = scene->GetBlockManager();

	std::list<GameBlock*> blockList = blockManger->FindBlock(this, 1);

	int moveX= _posx;
	int moveY = _posy;

	switch (_direction)
	{
	case LEFT:
		moveX = _posx - 1;
		break;
	case RIGHT:
		moveX=_posx + 1;
		break;
	case UP:
		moveY= _posy - 1;
		break;
	case DOWN:
		moveY= _posy + 1;
		break;
	}

	if (blockList.size() == 2)
	{
		if (map->CanMove(moveX,moveY))
		{
			map->ResetTile(this, _posx, _posy);
			map->DestoryTile(_posx, _posy);

			_posx = moveX;
			_posy = moveY;

			map->SetBlock(this, _posx, _posy);
		}
	}


}
void ArrowMoveBlock::Render()
{
	_BlockImg->render();
}



