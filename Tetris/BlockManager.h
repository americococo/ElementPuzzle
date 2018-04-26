#pragma once
#include <queue>
class Block;
class Map;
class BlockManger
{
public:
	BlockManger();
	~BlockManger();

	void Init();
	void Update(float deltaTime);

	void Render();
	


private:
	Map * _map;
	bool _isInstallBlock;


	void RandSpwan();


private:
	std::queue<Block*> _blockSelect;
};

