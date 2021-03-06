#pragma once
#include "Scene.h"

class BlockManger;
class Map;
class Sprite;

class Font;

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

private:
	BlockManger * _blockManager;
public:
	BlockManger * GetBlockManager() { return _blockManager; }


private:
	Font * _font;
	int _score;

public:
	void GetScore(int score);
};
