#pragma once
#include "Block.h"

enum eGameBlockType
{
	DefaultBlock,
	
};

class GameBlock : public Block
{
public:
	GameBlock();
	~GameBlock();




	/*overriding*/ void Init();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
private:

};

