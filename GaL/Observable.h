#pragma once

#include "Observer.h"
#include <vector>
#include <hash_map>
#include <iostream>
#include "TextOutPut.h"

namespace GaL{

	//!イベントを発生させたいクラスにはこのクラスを継承させる
	template<class T>	//T<-誰に?
	class Observable{
		private:
		vector<IObserver<T>*> observers;
		
	public:
		//static hash_map<string,unsigned int> keys;	//!イベントトリガーキー

		vector<IObserver<T>*> getObservers(){
			return observers;
		}

		void addObserver(IObserver<T>* _observer){
			observers.push_back(_observer);
		}

		//!オブザーバーを削除
		void removeObserver(IObserver<T>* _observer){
			typename vector<IObserver<T>*>::iterator it;
			it = find(observers.begin(),observers.end(),_observer);
				if (it != observers.end())
				{
					observers.erase(it);
				}
		}

		//!イベントの通知
		void notify(const string& _key){
			typename vector<IObserver<T>*>::iterator it;
			for (it = observers.begin(); it != observers.end(); it++)
			{
				if ((*it)->shouldNotify(_key))
				{
					(*it)->Event(static_cast<T*>(this),_key);
				}
			}
		}

		//!イベントを起こす条件
		virtual void makeEvent()=0;

		//!キー作成
		/*void makeKey(const string& _key){ 
			try{
				if (keys[_key] != NULL)
				{
					throw "Observable::makeKeyでキーが重複しました";
				}
				
			}
			catch(char* c){
				string s = string(c) + string(",") + _key + string("1") + string("として再登録します."); 
				TextOut::GetInstance()->PushString(s);
				_key += string("1");
			}
			keys[_key] = ID;
			ID++;
		}*/

	};

}