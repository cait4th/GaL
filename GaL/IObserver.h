#pragma once

#include <string>
#include <vector>

using namespace std;

namespace GaL{
	//!�C�x���g�̒ʒm���󂯎��ɂ͂��̃N���X���p������
	template<class T>	//T<-�N����?
	class IObserver
	{
	private:
		virtual bool shouldNotify(const string& _key)=0;

		//!_key�Ƃ����ʒm���������ɑ΂��鏈��
		virtual void Event(T* _sender,const string& _key)=0;

		template<class F>
		friend class Observable;
	};

}