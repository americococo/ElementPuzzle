#pragma once
#include "Scene.h"

class BlockManger;
class Map;
class Sprite;

class GameScene :public Scene
{
public:
	GameScene();
	~GameScene();

	void Start();
	void Update(float deltaTime);
	void Render();
	void Stop();

private:
	Sprite * _backGround;

	Map * _map;

public:
	Map * GetMap() { return _map; }


private:
	BlockManger * _blockManager;
public:
	BlockManger * GetBlockManager() { return _blockManager; }
};
