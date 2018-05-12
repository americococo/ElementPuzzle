#pragma once
#include "GameBlock.h"

class  BombBlock: public GameBlock
{
public:
	BombBlock();
	~BombBlock();




	/*overriding*/ void Init();
	/*overriding GameBlock*/ void Start();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
private:

};

