#pragma once
#pragma once
#include "GameBlock.h"

enum eDirection
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

class  ArrowMoveBlock : public GameBlock
{
public:
	ArrowMoveBlock();
	~ArrowMoveBlock();




	/*overriding*/ void Init();
	/*overriding GameBlock*/ void Start();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
private:
	eDirection _direction;
};
