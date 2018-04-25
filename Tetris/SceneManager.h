#pragma once
class Scene;
enum eScene;

#include <map>
class SceneManager
{
private:
	SceneManager();
	static SceneManager * _instance;
public:
	~SceneManager();
	static SceneManager * GetInstance();


private:
	Scene * _scene;
	std::map<eScene, Scene *> _sceneMap;


public:
	void ChangeScene(eScene type);
	void InitScene();

	void Update(float deltaTime);
	void Render();

public:
	Scene * GetScene() { return _scene; }
};