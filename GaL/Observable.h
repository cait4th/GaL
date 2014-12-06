#pragma once

#include "Observer.h"
#include <vector>
#include <hash_map>
#include <iostream>
#include "TextOutPut.h"

namespace GaL{

	//!�C�x���g�𔭐����������N���X�ɂ͂��̃N���X���p��������
	template<class T>	//T<-�N��?
	class Observable{
		private:
		vector<IObserver<T>*> observers;
		
	public:
		//static hash_map<string,unsigned int> keys;	//!�C�x���g�g���K�[�L�[

		vector<IObserver<T>*> getObservers(){
			return observers;
		}

		void addObserver(IObserver<T>* _observer){
			observers.push_back(_observer);
		}

		//!�I�u�U�[�o�[���폜
		void removeObserver(IObserver<T>* _observer){
			typename vector<IObserver<T>*>::iterator it;
			it = find(observers.begin(),observers.end(),_observer);
				if (it != observers.end())
				{
					observers.erase(it);
				}
		}

		//!�C�x���g�̒ʒm
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

		//!�C�x���g���N��������
		virtual void makeEvent()=0;

		//!�L�[�쐬
		/*void makeKey(const string& _key){ 
			try{
				if (keys[_key] != NULL)
				{
					throw "Observable::makeKey�ŃL�[���d�����܂���";
				}
				
			}
			catch(char* c){
				string s = string(c) + string(",") + _key + string("1") + string("�Ƃ��čēo�^���܂�."); 
				TextOut::GetInstance()->PushString(s);
				_key += string("1");
			}
			keys[_key] = ID;
			ID++;
		}*/

	};

}