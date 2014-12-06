#pragma once
#include <iostream>

namespace GaL{
	class BaseFactory{
	private:

	public:
		BaseFactory(){}
		virtual ~BaseFactory(){}

		//!InitializeされるのでComponentクラスを継承している前提のFactory

		//!ST型でインスタンス化する(型変換に注意)
		template<class ST,class InfoT>
		ST* CreateObject(const InfoT& _info){
			ST* t = new ST(_info);
			t->Initialize();
			return t;
			//return NULL;
		}
		//!外部データ無し
		template<class ST>
		ST* CreateObject(){
			ST* t = new ST();
			t->Initialize();
			return t;
		}

	};

}