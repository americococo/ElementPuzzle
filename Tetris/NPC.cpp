#include "NPC.h"
#include "Map.h"
#include "ComponentSystem.h"
#include "MoveState.h"
#include "Stage.h"
#include "GameSystem.h"
#include "GlobalType.h"
NPC::NPC(std::wstring name, std::wstring  scriptName, std::wstring  textureName) :Charcter(name, scriptName, textureName)
{
	componentType = eComponentType::CT_NPC;

	int speed = (rand() % 1) + 500;
	_moveTime = (float)speed / 1000.0f;

	_hp = 3;
}
NPC::~NPC()
{

}

void NPC::UpdateAi(float deltaTime)
{
	std::vector<eComponentType> compareTpyeList;
	compareTpyeList.push_back(eComponentType::CT_MONSTER);
	Map* map = GameSystem::GetInstance()->getStage()->getMap();
	Component * findEnemy = ComponentSystem::GetInstance()->FindComponentInRange(map,this, 5, compareTpyeList);

	if (NULL != findEnemy)
	{
		//Map * map = (Map*)ComponentSystem::GetInstance()->FindComponent(L"TestMap");
		Map* map = GameSystem::GetInstance()->getStage()->getMap();
		//적을 찾았즘 도망
		eDirection direction = eDirection::NONE;
		for (int finDir = 0; finDir < 4; finDir++)
		{
			int newTileX = _tileX;
			int newTileY = _tileY;

			switch (finDir)
			{
			case eDirection::LEFT:
				newTileX--;
				break;
			case eDirection::RIGHT:
				newTileX++;
				break;
			case eDirection::UP:
				newTileY--;
				break;
			case eDirection::DOWN:
				newTileY++;
				break;
			}

			TilePosition NpcNewPosition;
			NpcNewPosition.x = newTileX;
			NpcNewPosition.y = newTileY;

			if (map->CanMoveTileMap(NpcNewPosition))
			{
				_currentDirtion = (eDirection)finDir;
				_state->NextState(eStateType::ET_MOVE);
				break;
			}
		}
	}
	else
	{
		Charcter::UpdateAi(deltaTime);
	}

}

