#include "Block.h"
#include "Sprite.h"
#include "GameSystem.h"
#include <stdio.h>
Block::Block() {}
Block::~Block() {}

void Block::Init()
{
	_posx = GameSystem::GetInstance()->GetWidth() / 2;
	_posy= GameSystem::GetInstance()->GetHeight() / 2;
	_BlockImg = new Sprite(L"Block.png", L"Block.json");
	_BlockImg->Init();
	SetPostion(_posx, _posy);
	_durationTime = 0.0f;
	_updateTime = 0.1;
}
void Block::Update(float deltaTime)
{
	_BlockImg->Update(deltaTime);
	KeyDown();
	SetPostion(_posx, _posy);
}
void Block::SetPostion(float posX, float posY)
{
	_BlockImg->setPostition(posX, posY);
	_left = posX - _BlockImg->GetWidth();
	_right = posX + _BlockImg->GetWidth();

	_top = posY - _BlockImg->GetHeight();
	_bottom = posY + _BlockImg->GetHeight();

}

void Block::Render()
{
	_BlockImg->render();
}
void Block::KeyDown()
{
	if (GameSystem::GetInstance()->IsKeyDown(VK_LEFT))
	{
		_posx = 0 + _BlockImg->GetWidth()/2;
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_RIGHT))
	{
		_posx = GameSystem::GetInstance()->GetWidth() - _BlockImg->GetWidth()/2;
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_UP))
	{
		_posy = 0 + _BlockImg->GetHeight()/2;
	}
	if (GameSystem::GetInstance()->IsKeyDown(VK_DOWN))
	{
		_posy = GameSystem::GetInstance()->GetHeight() - _BlockImg->GetHeight()/2;
	}
}