#pragma once

#include "Observable.h"
#include "ComponentContainer.h"
#include "Data.h"


namespace GaL{

	//!���V�[���N���X
	class BaseScene : public Observable<BaseScene>, public Component{
	private:
		
	public:
		BaseScene(const Data& _info){Initialize();}
		virtual ~BaseScene();

		virtual void Update(Component* _sender)override;
		void Draw()override;

		virtual void Initialize()override;

		//!�R���e�i���̐����t���O���܂�Ă�����̂�delete
		void DeleteContainer();

		ComponentContainer* getContainer();

	private:
		ComponentContainer* container;
	};

}