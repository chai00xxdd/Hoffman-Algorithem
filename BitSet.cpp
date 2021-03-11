#include "BitSet.h"



BitSet::BitSet(big bits)
	:bits(bits)
{
	big bytes = (bits / 8)+1; 
}
void BitSet::push_back(bool bit)
{
	if (bytes.length()==0)
	{
		bytes.push_back(0);
	}
	else if (!isEnoughSpace())
	{
		int oldPhy = bytes.length();
		int newPhy = bytes.length() * 2;
		bytes.resize(newPhy);
		for (int i = oldPhy; i < bytes.length(); i++)
			bytes[i] = 0;
	}
	updateBit(bits++, bit);
}
bool BitSet::getBit(big index)
{
	unsigned char bit_index = 7-(index % 8);
	return getByte(index)&(1 << bit_index);
}
void BitSet::setBit(big index)
{
	unsigned int bit_index = 7 - (index % 8);
	unsigned char&byte = getByte(index);
	byte|=(1 << bit_index);
}
void BitSet::clrBit(big index)
{
	unsigned int bit_index = 7-(index % 8);
	unsigned char&byte = getByte(index);
	byte&=~(1 << bit_index);
}
bool BitSet::isOn(big index)
{
	return getBit(index);
}

void BitSet::updateBit(big index, bool value)
{
	
	if (value == 1)
	{
		setBit(index);
	}
	else clrBit(index);
}
bool BitSet::isEnoughSpace()
{
	big totalBytes = bits / 8;
	return totalBytes < bytes.length();
}

unsigned char&BitSet::getByte(big index)
{
	return bytes[static_cast<int>(index) / 8];
}