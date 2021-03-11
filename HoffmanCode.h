#pragma once
#include"TreeNode.h"
#include"BSearchTree.h"
#include"CharCode.h"
class HoffmanCode
{
public:
	class Pair
	{
	   public:
	   char ch;
	 int frequency;
	};
	friend int main();
private:
	 Array<CharCode> codes;
	 long long file_size=0;
	TreeNode*hoffman_tree=nullptr;
	//the function get the root of homman tree and create the codes
	 void getCodesRec(TreeNode*root, Array<int>&code,int index);
	 //hoffman algorithem from forest of leafs
	 void build(const Array<TreeNode*>&forest);
public:
	//ctors dtors
	HoffmanCode() = default;
	HoffmanCode(const HoffmanCode&other) { *this = other; }
	HoffmanCode(std::istream&in);
	~HoffmanCode();
	//getters

	 Array<CharCode>& getCodes() { return codes; }
	
	long long getFileSize()const { return file_size; }
	bool isEmpty()const { return hoffman_tree == nullptr;}
	//delete the tree and clear the codes
	void makeEmpty(); 
	//prints the codes of the chars
	void showCodes()const;
	//build a new tree and codes from a file
	void build(std::istream&in);
	//build a new tree and codes from {char,freq} array
	void build(const Array<Pair>&pairs);
	//operators
	friend std::ostream& operator<<(std::ostream&out, const HoffmanCode&other);
	void operator=(const HoffmanCode&other);

	
};
std::ostream& operator<<(std::ostream&out, const HoffmanCode&other);
