#pragma once
#include<iostream>
#include"Array.h"
class TreeNode
{
private:
	char key='?';
	int data = 0;
	TreeNode*left, *right,*parent=nullptr;
	static void CreateForestRec(const TreeNode*,Array<TreeNode*>&);
public:
	//ctor
	TreeNode(char key,int data=0,TreeNode*left=nullptr,TreeNode*right=nullptr)
		:key(key),data(data),left(left),right(right)
	{

	}
	
	//getters
	TreeNode*getLeft()const { return left; }
	TreeNode*getRight()const { return right; }
	TreeNode*getParent()const { return parent; }
	//return the son that is not null with left priority
	//if both sons are null return null
	TreeNode*getSon()const {return left ? left : right; }
	char getKey()const { return key; }
	int getData()const { return data; }
	//setters
	void setLeftAndParent(TreeNode*left);
	void setRightAndParent(TreeNode*right);
	void setLeft(TreeNode*left);
	void setRight(TreeNode*right);
	void setParent(TreeNode*parent) { this->parent = parent; }
	void setData(int data) { this->data = data; }
	void setKey(int key) { this->key = key; }
	//return true if node is leaf
	bool isleaf()const { return left == nullptr&&right == nullptr; }
	//return true when have two sons
	bool isTwoChilds()const { return left!=nullptr && right!=nullptr; }
	//return true when have one son
	bool isOneChild()const { return !(isleaf() || isTwoChilds()); }
	//return the heigt
	int getHeight()const { return TreeNode::height(this); }
	//the function replace son with new son
	void replaceSon(TreeNode*son, TreeNode*newSon);

	//count the number of edges in the tree
	static int countEdges(const TreeNode*root);

	//free the roots and all his sons
	static void freeTree(TreeNode*root);
	//print functions
	static void inorder(const TreeNode*root);
	static void preorder(const TreeNode*root);
	static void postorder(const TreeNode*root);
	//return the height of the tree
	static int height(const TreeNode*root);
	//return the number of elemets in the tree
	static int count(const TreeNode*root);
	static Array<TreeNode*> createNewForest(const TreeNode*root);

	//operators
	friend std::ostream& operator<<(std::ostream&out, const TreeNode&node);
	bool operator<(const TreeNode&other)const { return key < other.key; }
	bool operator>(const TreeNode&other)const { return key > other.key; }
	bool operator==(const TreeNode&other)const { return key == other.key; }
	

	
};
std::ostream& operator<<(std::ostream&out, const TreeNode&node);

