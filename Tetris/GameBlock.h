#pragma once
#include "Block.h"

enum eGameBlockType
{
	DefaultBlock,
	BOMBBLOCK	
};


class GameBlock : public Block
{
public:
	GameBlock();
	~GameBlock();




	/*overriding*/ void Init();
	virtual void Start();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
protected:
	eGameBlockType _Gameblocktype;
};

