#pragma once

#include "Observable.h"
#include "Component.h"

namespace GaL{

	//!�R���|�[�l���g���i�[����N���X
	class ComponentContainer : public Observable<Component>, public Component{
	public:
		ComponentContainer();
		virtual ~ComponentContainer();

		//!�R���|�[�l���g��ǉ�
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