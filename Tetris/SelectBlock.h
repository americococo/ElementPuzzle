#pragma once
#include "Block.h"
class Font;
class SelectBlock : public Block
{
public:
	SelectBlock();
	~SelectBlock();




	/*overriding*/ void Init();
	/*overriding*/ void Update(float deltaTime);
	/*overriding*/ void Render();
private:
	Font * _font;

};

