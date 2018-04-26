#include "Map.h"
#include "TileCell.h"

Map::Map()
{
	_tileList.clear();
}
void Map::Init(int sizeX,int sizeY)
{
	std::vector<TileCell*> col;
	col.clear();

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			TileCell * tile = new TileCell();
			tile->Init(x, y);
			col.push_back(tile);
		}
		_tileList.push_back(col);
		col.clear();
	}

	_sizeX = sizeX;
	_sizeY = sizeY;
}

void Map::Update(float deltaTime)
{
	for (int y = 0; y < _sizeY; y++)
	{
		for (int x = 0; x < _sizeX; x++)
		{
			_tileList[y][x]->Update(deltaTime);
		}
	}
}
void Map::Render()
{
	for (int y = 0; y < _sizeY; y++)
	{
		for (int x = 0; x < _sizeX; x++)
		{
			_tileList[y][x]->Render();
		}
	}
}
bool Map::CanMove(int posX,int posY)
{
	if (posX >= _sizeX || posX <0)
		return false;
	if(posY >= _sizeY || posY <0)
		return false;


	return _tileList[posY][posX]->CanMove();
}
void Map::SetBlock(Block *block,int posX,int posY)
{
	_tileList[posY][posX]->SetBlock(block);
}
void Map::ResetTile(Block *block, int posX, int posY)
{
	_tileList[posY][posX]->ReSetTile(block);
}
void Map::GetBlockList(std::list<Block*>& blockList, int posX, int posY)
{
	_tileList[posY][posX]->GetBlockList(blockList);
}
Map::~Map()
{
}