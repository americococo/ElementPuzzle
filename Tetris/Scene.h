#pragma once
enum eScene
{
	TITLE,
	GAME
};
class Scene
{
public:
	Scene();
	~Scene();

	virtual void Start();
	
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Stop();
};
