#pragma once

#include <string>
#include <fstream>

using namespace std;

namespace GaL{

class TextOutPut{	//!シングルトン化
private:
	TextOutPut(){}
	TextOutPut(const TextOutPut& to);
	TextOutPut& operator=(const TextOutPut& to);

	string output;
	ofstream ofs;

public:
	virtual ~TextOutPut();

	static TextOutPut* GetInstance();

	//!出力するファイルを指定
	void SetFile(const string& _name);

	//!ファイルに追記
	void PushString(const string& _str);
};

}