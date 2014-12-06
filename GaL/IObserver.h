#pragma once

#include <string>
#include <vector>

using namespace std;

namespace GaL{
	//!イベントの通知を受け取るにはこのクラスを継承する
	template<class T>	//T<-誰から?
	class IObserver
	{
	private:
		virtual bool shouldNotify(const string& _key)=0;

		//!_keyという通知が来た時に対する処理
		virtual void Event(T* _sender,const string& _key)=0;

		template<class F>
		friend class Observable;
	};

}