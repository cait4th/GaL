#pragma once

#include <string>
#include <hash_map>

using namespace std;

namespace GaL{
	//!�O���f�[�^�Ǘ�
	class Data{
	private:
		virtual void LoadFromFile(const string& _file)=0;
	public:
		Data(const string& _filename){}
		virtual ~Data(){}

	protected:
		//hash_map<const string,const string> data;
	};

}