#pragma once
#define FILESCALE 48
class Sprite;

class Block
{
public:
	Block();
	~Block();



	void Init();
	void Update(float deltaTime);
	void Render();

private:
	Sprite * _BlockImg;

	int _left;
	int _right;
	int _top;
	int _bottom;

	int _posx;
	int _posy;

public:
	void SetPostion(float posX, float posY);

public:
	void KeyDown();



private:
	float _durationTime;
	float _updateTime;
};
