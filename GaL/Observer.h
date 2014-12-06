#pragma once 

#include "IObserver.h"

namespace GaL{
	template<class T>
	class Observer : public IObserver<T>{
	public:
		virtual void Event(T* _sender,const string& _key)=0;

		//!キーの追加
		void addKey(const string& _key){
			observerKeys.push_back(_key);
		}

	private:
		vector<string> observerKeys;	//!イベントとして使用するキー

		//!キーが登録されているか
		bool shouldNotify(const string& _key)override{
			typename vector<string>::iterator it = observerKeys.begin();
			while (it != observerKeys.end())
			{
				if ((*it) == _key)
				{
					return true;
				}
				else
				{
					++it;
				}
			}
			return false;
		}
		
	};

}