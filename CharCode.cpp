#include "CharCode.h"
#include"AsciConvertor.h"
CharCode::CharCode(char ch, long long frequency, const Array<int>& code)
	:ch(ch),frequency(frequency),code(code)
{

}

std::ostream& operator<<(std::ostream&out,const CharCode&c)
{
	AsciConvertor convertor;
	out << convertor(c.ch) << " code is ";
	for (int i = 0; i < c.code.length(); i++)
		out << c.code[i];
	return out;
}