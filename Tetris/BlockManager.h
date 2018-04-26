#pragma once
#include <queue>
#include <list>
class Block;
class Map;

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
	bool _isInstallBlock;


	void RandSpwan();


private:
	std::queue<Block*> _blockSelect;


public:
	std::list<Block*> FindBlock(Block * finder);
};

