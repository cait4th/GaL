#pragma once

#include "Observable.h"
#include "Component.h"

namespace GaL{

	//!コンポーネントを格納するクラス
	class ComponentContainer : public Observable<Component>, public Component{
	public:
		ComponentContainer();
		virtual ~ComponentContainer();

		//!コンポーネントを追加
		void AddComponent(Component* _component);

		void Update(Component* _sender)override;
		void Draw()override;
		
		void Initialize()override{}
		void makeEvent()override{}

		void Delete();

	private:
		vector<Component*> components;

		vector<Component*>::iterator itr;
	};

}