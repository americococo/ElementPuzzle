#pragma once
class Sprite;
class Block;
#include <list>
class TileCell
{
public:
	TileCell();
	~TileCell();


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
	bool _isMovableTile;
public:
	bool CanMove() { return _isMovableTile; }
	void SetCanMove(bool isMove) { _isMovableTile = isMove; }

public:
	void SetBlock(Block * block);
	
};
