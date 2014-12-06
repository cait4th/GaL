#pragma once

#include <string>
#include <fstream>

using namespace std;

namespace GaL{

class TextOut{	//!�V���O���g����
private:
	TextOut(){}
	TextOut(const TextOut& to);
	TextOut& operator=(const TextOut& to);

	string output;
	ofstream ofs;

public:
	virtual ~TextOut();

	static TextOut* GetInstance();

	//!�o�͂���t�@�C�����w��
	void SetFile(string& _name);

	//!�t�@�C���ɒǋL
	void PushString(string& _str);
};

}