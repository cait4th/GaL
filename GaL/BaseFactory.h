#pragma once
#include <iostream>

namespace GaL{
	class BaseFactory{
	private:

	public:
		BaseFactory(){}
		virtual ~BaseFactory(){}

		//!Initialize�����̂�Component�N���X���p�����Ă���O���Factory

		//!ST�^�ŃC���X�^���X������(�^�ϊ��ɒ���)
		template<class ST,class InfoT>
		ST* CreateObject(const InfoT& _info){
			ST* t = new ST(_info);
			t->Initialize();
			return t;
			//return NULL;
		}
		//!�O���f�[�^����
		template<class ST>
		ST* CreateObject(){
			ST* t = new ST();
			t->Initialize();
			return t;
		}

	};

}