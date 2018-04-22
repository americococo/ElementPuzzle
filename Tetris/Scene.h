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

	void Start();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	void Stop();
};
