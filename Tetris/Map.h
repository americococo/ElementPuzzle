#pragma once

#include <vector>
class TileCell;
class Block;
class GameBlock;
#include <list>
class Map
{
public:
	Map();
	~Map();


	void Init(int sizeX,int sizeY);
	void Update(float deltaTime);
	void Render();
private:
	std::vector < std::vector<TileCell*>> _tileList;
	
	int _sizeX;
	int _sizeY;

public:
	int GetSizeX() { return _sizeX; }
	int GetSizeY() { return _sizeY; }

public:

	bool CanMove(int posX,int posY);

	bool CanPutBlock();
public:
	void SetBlock(Block *block, int posX, int posY);
	void ResetTile(Block *block, int posX, int posY);
	void DestoryTile(int posX, int posY);
	void GetBlockList(std::list<GameBlock*>& blockList,int posX,int posY);

	void RemoveBlock(Block * block, int posX, int posY);

	float Density();
};

