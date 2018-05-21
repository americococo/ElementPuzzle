#pragma once
#include "GameBlock.h"

class  RockBlock : public GameBlock
{
public:
	RockBlock();
	~RockBlock();




	/*overriding*/ void Init();
	/*overriding GameBlock*/ void Start();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
private:

};

