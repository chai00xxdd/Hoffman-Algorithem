#pragma once
#include"TreeNode.h"
#include<iostream>

class BSearchTree
{
private:
	
	TreeNode*root=nullptr;
	bool todelete = true;
public:
	//ctors dtors
	BSearchTree(std::istream&in);
	BSearchTree(const BSearchTree&other) = delete;
	BSearchTree() = default;
	//if todelete is true the dtor will delete root
	explicit BSearchTree(TreeNode*root,bool todelete=true);
	~BSearchTree();
	//BSEARCH TREE FUNCTIONS
	void makeEmpty();
	bool isEmpty()const { return root == nullptr; }
	void insert(char key);
	 bool deleteKey (char key);
	 TreeNode*find(char key)const;
	 TreeNode*min()const;
	 TreeNode*max()const;

	 //extras
	const TreeNode*getRoot()const { return root; }
	int height()const { return TreeNode::height(root); }
	
	//operators
	friend std::ostream& operator<<(std::ostream&out,const  BSearchTree&t);
	void operator=(const BSearchTree&other)=delete;
	
	
};
 




	


