#pragma once
#include<iostream>
#include"Array.h"
class CharCode
{
	char ch;
	long long frequency;
	Array<int> code;
	public:
	//ctors
	CharCode() :CharCode('?', 0,Array<int>(0)) {}
	CharCode(char ch, long long frequency, const Array<int> &code);
	CharCode(const CharCode&other) = default;
	//getters
	char getChar()const { return ch; }
	long long getFrequency()const { return frequency; }
	const Array<int>&getCode()const { return code; }
	 Array<int>&getCode() { return code; }
	long long getWeight()const { return frequency * code.length(); }

	//setters
	void setChar(char ch) { this->ch = ch;}
	void setFrequency(long long f) { this->frequency = f; }
	void setCode(const Array<int>&code) { this->code = code; }
	//operators
	friend std::ostream& operator<<(std::ostream&out,const CharCode&other);
};
std::ostream& operator<<(std::ostream&out,const CharCode&other);
