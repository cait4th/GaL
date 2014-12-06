#pragma once

#include "Data.h"
#include "BaseScene.h"
#include "BaseFactory.h"
#include "ComponentContainer.h"

using namespace GaL;


class SceneFactory : public Component,
	public BaseFactory<BaseScene,Data>, public IObserver<SceneFactory>{
private:
	ComponentContainer* scenes;
public:
	SceneFactory();
	~SceneFactory();

	void Initialize()override;

	void Update(Component* _sender)override;
	void Draw()override{}

	void Event(SceneFactory* _sender,const string& _key)override;
};