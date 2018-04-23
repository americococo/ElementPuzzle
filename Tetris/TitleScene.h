#pragma once
#include "Scene.h"
class Sprite;
class TitleScene:public Scene
{
public:
	TitleScene();
	~TitleScene();

	void Start();
	void Update(float deltaTime);
	void Render();

	void Stop();
private:
	Sprite * _backGround;
};
