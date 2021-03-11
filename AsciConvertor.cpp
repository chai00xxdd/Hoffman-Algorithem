#include "AsciConvertor.h"
#include<iostream>
std::string AsciConvertor::convert(char c)
{
	if (c == 32)
	{
		return "'SPACE'";
	}
	else if (c == 10)
	{
		return "'NEW LINE'";
	}
	else if (c ==9)
	{
		return "'TAB'";
	}
	else
	{
		return "'"+std::string({ c })+"'";
	}
 }