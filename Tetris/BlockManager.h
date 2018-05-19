#pragma once

#include <list>
#include <map>
#include <queue>


class Block;
class Map;
class GameBlock;
class Font;
class BlockManger
{
public:
	BlockManger();
	~BlockManger();
public:
	void Init();
	void Update(float deltaTime);

	void Render();
	


private:
	Map * _map;


public:
	Map * GetMap() { return _map; }



private:
	std::queue<Block*> _blockIndex;


public:
	std::list<GameBlock*> FindBlock(Block * finder, int range);


private:

	Font * _font;
};

