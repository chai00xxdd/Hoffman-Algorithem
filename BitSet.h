#pragma once
#include"Array.h"
typedef unsigned long long big;
class BitSet
{
private:
	Array<unsigned char>bytes;
	big bits = 0;
	void updateBit(big index, bool value);
	bool isEnoughSpace();
	unsigned char& getByte(big index);
public:
	BitSet(big bits=0);
	void push_back(bool bit);
	bool getBit(big index);
	void setBit(big index);
	void clrBit(big index);
	bool isOn(big index);
	big length()const { return bits; }

};

