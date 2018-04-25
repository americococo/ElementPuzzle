#pragma once
#include "Block.h"
class BlanBlock : public Block
{
public:
	BlanBlock();
	~BlanBlock();




	/*overriding*/ void Init();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
private:

};

