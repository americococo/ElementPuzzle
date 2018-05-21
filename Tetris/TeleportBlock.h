#pragma once
#include "GameBlock.h"

class  TeleportBlock : public GameBlock
{
public:
	TeleportBlock();
	~TeleportBlock();




	/*overriding*/ void Init();
	/*overriding GameBlock*/ void Start();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
private:

};

