#pragma once

#include "IObserver.h"
#include <vector>

using namespace std;

namespace GaL{

	//!コンポーネントクラス
	class Component {
	private:
		bool isInitialize;

	public:
		Component();
		virtual ~Component();

		virtual void Update(Component* _sender)=0;
		virtual void Draw()=0;

		virtual void Initialize(){isInitialize = true;};

		bool IsInitialise(){return isInitialize;}

		bool IsValid(){
			return isValid;
		}
		bool IsVisible(){
			return isVisible;
		}
		bool IsAlive(){
			return alive;
		}

		void SetValid(bool _v){
			isValid = _v;
		}
		void SetVisivle(bool _v){
			isVisible = _v;
		}
		void SetAlive(bool _a){
			alive = _a;
		}

	private:
		bool isValid;
		bool isVisible;

		//!このフラグを折るとメモリから消去する
		bool alive;

	};

}