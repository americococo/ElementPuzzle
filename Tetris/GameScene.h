#pragma once
#include "Scene.h"
class Sprite;
class Block;
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
	Block * _block;
};
