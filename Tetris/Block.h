#pragma once

class Sprite;

class Block
{
public:
	Block();
	~Block();



	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

protected:
	Sprite * _BlockImg;
	int _RealPostionX;
	int _RealPostionY;

	int _posx;
	int _posy;


	int _Width;
	int _Height;
public:
	Sprite * GetSprite() { return _BlockImg; }
	void SetPosition(int positionX, int positionY);

	int GetPosX() { return _posx; }
	int GetPosY() { return _posy; }
};
