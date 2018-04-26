#pragma once
class Sprite;
class Block;
#include <list>
class TileCell
{
public:
	TileCell();
	~TileCell();

	void ReSetTile(Block * block);
	void Init(int posX,int posY);
	void Update(float deltaTime);
	void Render();

private:
	int _realPosX;
	int _realPosY;
	int _posX;
	int _posY;

	std::list<Block*> Tile;
	

	int _Width;
	int _Height;


public:
	bool CanMove();


public:
	void SetBlock(Block * block);

	void GetBlockList(std::list<Block*>& blockList);
};
