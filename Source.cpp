/*
the program get a name of a txt file
from the user (the user must write .txt as well)
then the program read all the chars from the file
and creating the hoffman code of each char
and prints it to the screen
*/
#include<iostream>
#include<fstream>
#include<string>
#include"HoffmanCode.h"
#include<exception>
using namespace std;
int main()
{
	cout << "enter txt file name:";
	std::string file_name;
	std::getline(std::cin, file_name);
	std::ifstream file(file_name,ios::in);
	if (!file)
	{
		cout << "invalid input" << endl;
		return 1;
	}
	try
	{
	  HoffmanCode code(file);
      cout << code << endl;
	}
	catch (std::exception&e)
	{
		cout << "invalid input"<<endl;
		cout << e.what() << endl;
	}
	file.close();
	
	
}


