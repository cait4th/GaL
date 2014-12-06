#pragma once

#include <string>
#include <fstream>

using namespace std;

namespace GaL{

class TextOutPut{	//!�V���O���g����
private:
	TextOutPut(){}
	TextOutPut(const TextOutPut& to);
	TextOutPut& operator=(const TextOutPut& to);

	string output;
	ofstream ofs;

public:
	virtual ~TextOutPut();

	static TextOutPut* GetInstance();

	//!�o�͂���t�@�C�����w��
	void SetFile(const string& _name);

	//!�t�@�C���ɒǋL
	void PushString(const string& _str);
};

}