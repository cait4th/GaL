#pragma once 

#include "IObserver.h"

namespace GaL{
	template<class T>
	class Observer : public IObserver<T>{
	public:
		virtual void Event(T* _sender,const string& _key)=0;

		//!�L�[�̒ǉ�
		void addKey(const string& _key){
			observerKeys.push_back(_key);
		}

	private:
		vector<string> observerKeys;	//!�C�x���g�Ƃ��Ďg�p����L�[

		//!�L�[���o�^����Ă��邩
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