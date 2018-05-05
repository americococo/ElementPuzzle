#pragma once
class Sprite;
class Block;
#include <list>
#include <queue>
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


private:
	std::queue<Block*> _deleteBlock;

public:
	bool CanMove();


public:
	void SetBlock(Block * block);
	void DestoryBlock();
	void GetBlockList(std::list<Block*>& blockList);
};
