#include "Map.h"
#include "TileCell.h"
#include "GameBlock.h"

Map::Map()
{
	_tileList.clear();
}
void Map::Init(int sizeX, int sizeY)
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
bool Map::CanMove(int posX, int posY)
{
	if (posX >= _sizeX || posX < 0)
		return false;
	if (posY >= _sizeY || posY < 0)
		return false;


	return _tileList[posY][posX]->CanMove();
}

bool Map::CanPutBlock()
{
	for (int y = 0; y < _sizeY; y++)
	{
		for (int x = 0; x < _sizeX; x++)
		{
			if (_tileList[y][x]->CanMove() == true)
				return true;
		}
	}
	return false;
}

int Map::Density()
{
	int i = 0;
	for (int y = 0; y < _sizeY; y++)
	{
		for (int x = 0; x < _sizeX; x++)
		{
			if (_tileList[y][x]->CanMove() == false)
				i++;
		}
	}

	float totoal = (_sizeX * _sizeY);

	return (i / totoal) * 100;
}

void Map::SetBlock(Block *block, int posX, int posY)
{
	_tileList[posY][posX]->SetBlock(block);
}
void Map::ResetTile(Block *block, int posX, int posY)
{
	_tileList[posY][posX]->ReSetTile(block);
}
void Map::DestoryTile(int posX, int posY)
{
	_tileList[posY][posX]->DestoryBlock();
}
void Map::RemoveBlock(Block * block, int posX, int posY)
{
	_tileList[posY][posX]->RemoveBlock(block);
}
void Map::GetBlockList(std::list<GameBlock*>& blockList, int posX, int posY)
{
	_tileList[posY][posX]->GetBlockList(blockList);
}

TileCell * Map::GetTileCell(int posX,int posY)
{
	return	_tileList[posY][posX];
}

Map::~Map()
{
}