#pragma once

#include <string>
#include <fstream>

using namespace std;

namespace GaL{

class TextOut{	//!シングルトン化
private:
	TextOut(){}
	TextOut(const TextOut& to);
	TextOut& operator=(const TextOut& to);

	string output;
	ofstream ofs;

public:
	virtual ~TextOut();

	static TextOut* GetInstance();

	//!出力するファイルを指定
	void SetFile(string& _name);

	//!ファイルに追記
	void PushString(string& _str);
};

}