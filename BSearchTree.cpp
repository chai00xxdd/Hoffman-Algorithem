#include"BSearchTree.h"
#include<iostream>
#include<string>

BSearchTree::BSearchTree(std::istream&in)
	:root(nullptr)
{
	if (!in)
	{
		throw std::exception("bad file");
	}
	char ch = in.get();
	while (!in.eof())
	{
		if (!in.good())
		{
			throw std::exception("failed to load char from file");
			makeEmpty();
		}
		insert(ch);
		ch = in.get();
	}

}
BSearchTree::~BSearchTree()
{
	if(todelete)
	makeEmpty();
}
void BSearchTree::insert(char key)
{
	if (root == nullptr)
		root = new TreeNode(key, 1, nullptr, nullptr);
	else
	{
		TreeNode*saveRoot = root;
		bool inserted = false;
		while (root&&!inserted)
		{
			if (root->getKey() == key)
			{
				root->setData(root->getData() + 1);
				inserted = true;
			}
			else if (root->getKey() < key)
			{
				if (root->getRight() == nullptr)
				{
					root->setRightAndParent(new TreeNode(key, 1));
					inserted = true;
				}
				else
					root = root->getRight();
			}
			else
			{
				if (root->getLeft() == nullptr)
				{
					root->setLeftAndParent(new TreeNode(key, 1));
					inserted = true;
				}
				else
					root = root->getLeft();
			}
		}

		root = saveRoot;
	}
}
bool BSearchTree::deleteKey(char key)
{
	if (root == nullptr)
		return false;
	TreeNode*nodeToDelete = find(key);
	if (nodeToDelete == nullptr)
		return false;
	
	if (nodeToDelete == root&&root->isleaf())
	{
		makeEmpty();
	}
	else
	{
		TreeNode*father = nodeToDelete->getParent();
		if(nodeToDelete->isTwoChilds())
		{

			TreeNode*leftMax = BSearchTree(nodeToDelete->getLeft(),false).max();
			leftMax->getParent()->replaceSon(leftMax, leftMax->getLeft());
			nodeToDelete->setData(leftMax->getData());
			nodeToDelete->setKey(leftMax->getKey());
			nodeToDelete = leftMax;
		}
		else//nodeToDelete have one child or 0 childs
		{
			if (father)
			{
				father->replaceSon(nodeToDelete, nodeToDelete->getSon());
			}
			else//node To Delete is root
			{
				root->getSon()->setParent(nullptr);
				root = root->getSon();
			}
		}
		delete nodeToDelete;
		
	}
	return true;

	

}
BSearchTree::BSearchTree(TreeNode*root,bool todelete)
	:todelete(todelete),root(root)
{

}

TreeNode* BSearchTree::find(char key)const
{
	TreeNode*saveroot = root;
	TreeNode*result = nullptr;
	while (saveroot &&!result)
	{
		if (saveroot->getKey() == key)
		{
			result = saveroot;
		}
		else if (saveroot->getKey() < key)
			saveroot = saveroot->getRight();
		else
			saveroot = saveroot->getLeft();
	}
	return result;

}


 TreeNode*BSearchTree::min()const
{
	 TreeNode*minimum = root;
	while (minimum&&minimum->getLeft())
		minimum = minimum->getLeft();
	return minimum;
}
 TreeNode* BSearchTree::max()const
{
	TreeNode*maximum = root;
	while (maximum&&maximum->getRight())
		maximum = maximum->getRight();
	return maximum;

}

std::ostream& operator<<(std::ostream&out, const  BSearchTree&t)
{
	TreeNode::inorder(t.root);
	return out;
}

void BSearchTree::makeEmpty()
{
	TreeNode::freeTree(root);
	root = nullptr;
}



 