#include "TreeNode.h"
#include<iostream>

void TreeNode::freeTree(TreeNode*root)
{
	if (root == nullptr)
		return;
	freeTree(root->left);
	freeTree(root->right);
	delete root;
}

 void TreeNode::inorder(const TreeNode*root)
{
	if (root == nullptr)
		return;
	inorder(root->left);
	std::cout << *root << std::endl;
	inorder(root->right);
	
}
 void TreeNode::preorder(const TreeNode*root)
{
	 if (root == nullptr)
		 return;
	 std::cout << *root << std::endl;
	 preorder(root->left);
	 preorder(root->right);
	
	
}
 void TreeNode::postorder(const TreeNode*root)
{
	 if (root == nullptr)
		 return;

	 postorder(root->left);
	 postorder(root->right);
	 std::cout << *root << std::endl;

}
 void TreeNode::setLeft(TreeNode*left)
 {
	 this->left = left;
 }
 void TreeNode::setRight(TreeNode*right)
 {
	 this->right = right;
 }

 void TreeNode::setLeftAndParent(TreeNode*left)
 {
	 setLeft(left);
	 if (left)
	left->parent = this;
 }
 void TreeNode::setRightAndParent(TreeNode*right)
 {
	 setRight(right);
	 if (right)
		right->parent = this;
 }
 void TreeNode::replaceSon( TreeNode*son, TreeNode*newSon)
 {
	
	 if (son == nullptr)
		 return;
	 if (left == son)
		 setLeftAndParent(newSon);
	 else if (right == son)
		 setRightAndParent(newSon);
	 if (son->parent == this)
		 son->parent = nullptr;
	 

 }
 int TreeNode::height(const TreeNode*root)
 {
	 if (root == nullptr)
		 return -1;
	 if (root->isleaf())
		 return 0;
	 int left = 0, right = 0;
	 if (root->left)
		 left = height(root->left);
	 if (root->right)
		 right = height(root->right);
	 return 1 + (left > right ? left : right);


 }
 int TreeNode::count(const TreeNode*root)
 {
	 if (root == nullptr)
		 return 0;
	 return 1 + count(root->left) + count(root->right);
 }
 
 std::ostream& operator<<(std::ostream&out, const TreeNode&node)
 {
	 out << "key=" << node.key << " data=" << node.data;
	 return out;
 }
 int TreeNode::countEdges(const TreeNode*root)
 {
	 if (root == nullptr)
		 return 0;
	 int myEdges = 0;
	 if (root->left)
		 myEdges++;
	 if (root->right)
		 myEdges++;
	 return myEdges + countEdges(root->left)+countEdges(root->right);
 }
 void TreeNode::CreateForestRec(const TreeNode*root,Array<TreeNode*>&arr)
 {
	 if (root == nullptr)
		 return;
	 arr.push_back(new TreeNode(root->getKey(), root->getData()));
	 CreateForestRec(root->left, arr);
	 CreateForestRec(root->right, arr);
 }
  Array<TreeNode*> TreeNode::createNewForest(const TreeNode*root)
 {
	  Array<TreeNode*>forest;
	  if (root == nullptr)
		  return forest;
	  int size = count(root);
	  CreateForestRec(root, forest);
	  return forest;

 }