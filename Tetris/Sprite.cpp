#include "GameSystem.h"

#include "Sprite.h"
#include "Texture.h"
#include "ResourceManager.h"


#include <string>

#include<fstream>
#include <reader.h>//json ÆÄ½Ì

Sprite::Sprite(LPCWSTR textureFileName) :_textureFileName(textureFileName)
{
	_srcTexture = nullptr;
}

Sprite::~Sprite()
{
	if (_srcTexture != nullptr)
	{
		delete _srcTexture;
		_srcTexture = NULL;
	}
	
}

void Sprite::Init()
{

	WCHAR textureFileName[256];
	WCHAR scriptFileName[256];

	wsprintf(textureFileName, L"../Resource/Img/%s", _textureFileName);

	_srcTexture = ResourceManager::GetInstance()->LoadTexture(textureFileName);

	_sprite = GameSystem::GetInstance()->getSprite();

	_width = _srcTexture->GetTextureInfo().Width;
	_height = _srcTexture->GetTextureInfo().Height;

	srcTextureRect.left = 0;
	srcTextureRect.top = 0;
	srcTextureRect.right = _width + srcTextureRect.left;
	srcTextureRect.bottom = _height + srcTextureRect.top;

	_texturecolor = D3DCOLOR_ARGB(255, 255, 255, 255);

}

void Sprite::deInit()
{
	_srcTexture = NULL;
}
void Sprite::render()
{
	{
		D3DXVECTOR2 spriteCenter = D3DXVECTOR2(_width / 2.0f, _height / 2.0f);
		D3DXVECTOR2 translate = D3DXVECTOR2(_x - ((float)_width / 2.0f), _y - (_height / 2.0f));
		D3DXVECTOR2 scaling = D3DXVECTOR2(1.0f, 1.0f);

		D3DXMATRIX matrix;
		D3DXMatrixTransformation2D(
			&matrix,
			NULL,
			2.0f,
			&scaling,
			&spriteCenter,
			0,
			&translate
		);

		_sprite->SetTransform(&matrix);

		_sprite->Draw(_srcTexture->GetTextureDX(), &srcTextureRect, NULL, NULL, _texturecolor);
	}

}


void Sprite::Release()
{
	_srcTexture->Release();
}

void Sprite::Reset()
{
	Init();
}
void Sprite::setPostition(float posX, float posY)
{
	_x = posX;
	_y = posY;
}
int Sprite::GetWidth()
{
	return _srcTexture->GetTextureInfo().Width;

}
int Sprite::GetHeight()
{
	return _srcTexture->GetTextureInfo().Height;
}