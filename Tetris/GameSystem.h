#pragma once
#include "D3D11.h"
#include <D3DX9.h>
#include <vector>
#include <list>

#define RELEASE_COM(x){if(x){x->Release();x=NULL;}}
class Scene;
class Component;

class GameSystem
{

	//싱글턴
private:
	static GameSystem * _instance;
public:
	static GameSystem * GetInstance();


	
public:
	bool InitSystem(HINSTANCE hInstance, int nCmdShow);
	int Update();



	//direct3d
private:

	//dirext 9
private:
	LPDIRECT3DDEVICE9 _direxct3Ddevice;
	LPD3DXSPRITE _sprite;
	D3DPRESENT_PARAMETERS d3dpp;
public:
	bool initDirect3D();

private:
	HWND hWnd;
	bool isFULLScreen;
	int clientWidth;
	int clientheight;

private:
	GameSystem();
public:
	~GameSystem();


	//텍스쳐
private:
	
	Scene * _scene;


public:
	Scene * GetScene() { return _scene; }
	//get
public:
	int GetWidth();
	int GetHeight();
	LPD3DXSPRITE getSprite();
	LPDIRECT3DDEVICE9 getDevice();

	//입력

public:
	enum eKeyState
	{
		KEY_DOWN, KEY_UP
	};

public:
	void KeyDown(unsigned int keycode);
	void KeyUp(unsigned int keycode);

	void InitInput();

private:
	eKeyState _keystate[256];



public:
	bool IsKeyDown(unsigned int keycode);

	unsigned int isInputKey();

};