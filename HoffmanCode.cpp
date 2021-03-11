#include "HoffmanCode.h"
#include"MinHeap.h"
#include"AsciConvertor.h"
HoffmanCode::HoffmanCode(std::istream&in)
{
	build(in);
}
HoffmanCode::~HoffmanCode()
{
	
	makeEmpty();
}

void HoffmanCode::showCodes()const
{
	std::cout << "*****HOFFMAN CODE******" << std::endl;	
	if (codes.length() == 0)
		std::cout << "EMPTY!!!!" << std::endl;
	for (int i = 0; i < codes.length(); i++)
    {
	 std::cout<< codes[i] << std::endl;
	}
    std::cout << "file size is " << file_size <<" bits";
	
}

void HoffmanCode::getCodesRec(TreeNode*root, Array<int>&code,int index)
{
	if (root == nullptr)
		return;
	if (root->isleaf())
	{
	codes.push_back(CharCode(root->getKey(), root->getData(), code));
	codes.last().getCode().resize(index?index:1);
	file_size += codes.last().getWeight();
	}
	if (root->getLeft())
	{
		code[index] =0;
		getCodesRec(root->getLeft(), code, index + 1);
	}
	if (root->getRight())
	{
		code[index] =1;
		getCodesRec(root->getRight(), code, index + 1);
	}

}

std::ostream& operator<<(std::ostream&out, const HoffmanCode&other)
{
	const_cast<HoffmanCode&>(other).showCodes();
	return out;
}

void HoffmanCode::makeEmpty()
{
	 TreeNode::freeTree(hoffman_tree);
	 hoffman_tree = nullptr; 
	 file_size = 0;
	 codes.clear();
}

void HoffmanCode::build(std::istream&in)
{
	
	BSearchTree BSC(in);
	Array<TreeNode*>forest=TreeNode::createNewForest(BSC.getRoot());
	build(forest);
	
	
}

void HoffmanCode::build(const Array<Pair>&pairs)
{
	makeEmpty();
	Array<TreeNode*> forest(pairs.length());
	for (int i = 0; i < pairs.length(); i++)
		forest[i] = new TreeNode(pairs[i].ch,static_cast<int>(pairs[i].frequency));
	build(forest);
	

}

void HoffmanCode::build(const Array<TreeNode*> &forest)
{
	if (forest.length() == 0)
		return;
	makeEmpty();//clear the old data
	MinHeap priority_queue;
	priority_queue.BuildHeap(forest);//floyed-algorithem
	for (int i = 1; i < forest.length(); i++)//hofman-algorithem
	{
		TreeNode* left = priority_queue.deleteMin();
		TreeNode*right = priority_queue.deleteMin();
		TreeNode*node =
			new TreeNode('?', left->getData() + right->getData(), left, right);
		priority_queue.insert(node);

	}
	hoffman_tree = priority_queue.deleteMin();
	Array<int> code(hoffman_tree->getHeight() + 1);
	code[0] = 0;//for case only one root
	getCodesRec(hoffman_tree, code, 0);
}


void HoffmanCode::operator=(const HoffmanCode&other)
{
	makeEmpty();
	codes = other.codes;
	file_size = other.file_size;

}


