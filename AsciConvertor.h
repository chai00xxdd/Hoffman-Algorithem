#pragma once
#include<string>
class AsciConvertor
{	
public:
	static std::string convert(char c);
	std::string operator()(char c) { return convert(c); }
};

