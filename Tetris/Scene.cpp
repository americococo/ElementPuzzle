#include "Scene.h"
#include "GameSystem.h"
Scene::Scene() {}
Scene::~Scene() {}


void Scene::Start() 
{
	GameSystem::GetInstance()->InitInput(); 
}

void Scene::Update(float deltaTime) {}
void Scene::Render() {}
void Scene::Stop() {}