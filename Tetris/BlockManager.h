#pragma once
#include <queue>
#include <list>
#include <map>
enum eGameBlockType;
class Block;
class Map;
class GameBlock;
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

	void InstallGameBlock(eGameBlockType type);

public:
	Map * GetMap() { return _map; }
private:
	std::queue<Block*> _blockSelect;


public:
	std::list<Block*> FindBlock(Block * finder);



public:
	void MakeGameBlock();
};

