#pragma once

#include <vector>

#include <d3dx9.h>

class Texture;

class Sprite
{
private:
	//Frame * _frame;
	/*std::vector<Frame*> _frameList;
	int _currentFrame;*/


	//DirextX
private:
	
	// IDirect3DTexture9* _texture;
	RECT srcTextureRect;
	D3DCOLOR _texturecolor;
	//D3DXIMAGE_INFO textureInfo;
	
	LPDIRECT3DDEVICE9 _dirext3dDevice;
	LPD3DXSPRITE _sprite;

	LPCWSTR _textureFileName;
private:
	Texture * _srcTexture;

	int _width;
	int _height;
public:

	Sprite(LPCWSTR textureFileName);
	~Sprite();


	void Init();

	//void Init(int srcX,int srcY,int width,int height ,float delay);

	void deInit();
	
	void Release();
	void Reset();

	void render();

	void setPostition(float posX,float posY);


private:
	float _x;
	float _y;

public:
	int GetWidth();
	int GetHeight();
};