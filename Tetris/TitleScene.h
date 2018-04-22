#pragma once
#include "Scene.h"
class Sprite;
class TitleScene:public Scene
{
public:
	TitleScene();
	~TitleScene();

	void Init();
	void Update(float deltaTime);
	void Render();

private:
	Sprite * _backGround;
};
