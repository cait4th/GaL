#pragma once

#include "Observable.h"
#include "ComponentContainer.h"
#include "Data.h"


namespace GaL{

	//!基底シーンクラス
	class BaseScene : public Observable<BaseScene>, public Component{
	private:
		
	public:
		BaseScene(const Data& _info){Initialize();}
		virtual ~BaseScene();

		virtual void Update(Component* _sender)override;
		void Draw()override;

		virtual void Initialize()override;

		//!コンテナ内の生存フラグが折れているものをdelete
		void DeleteContainer();

		ComponentContainer* getContainer();

	private:
		ComponentContainer* container;
	};

}