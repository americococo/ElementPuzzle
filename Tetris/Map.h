#pragma once

#include <vector>
class TileCell;
class Block;
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

	bool CanMove(int posX,int posY);


public:
	void SetBlock(Block *block, int posX, int posY);
	void ResetTile(Block *block, int posX, int posY);

	void GetBlockList(std::list<Block*>& blockList,int posX,int posY);
};

