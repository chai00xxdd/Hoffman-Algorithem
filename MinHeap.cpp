#include"MinHeap.h"

MinHeap::MinHeap(int phy)
{
	if (phy > 0)
	{
		arr.resize(phy);
	}

}
MinHeap::MinHeap(const MinHeap&other)
	:arr(other.arr),log(other.log)
{

}
MinHeap::~MinHeap()
{
	
}
void MinHeap::BuildHeap(const Array<TreeNode*>&arr)
{
	this->arr = arr;
	log = arr.length();
	for (int i = (log / 2) - 1; i >= 0; i--)
		fixheap(i);

}

 bool MinHeap::isSmaller(TreeNode*t1, TreeNode*t2)
{
	 return t1->getData() < t2->getData();
}
bool MinHeap::insert(TreeNode*root)
{
	if (log == arr.length())
		return false;
	arr[log++] = root;
	fixInsert();
	return true;

}

void MinHeap::fixInsert()
{
	int node = log - 1;
	while (Parent(node) >= 0 && isSmaller(arr[node],arr[Parent(node)]))//while parent that is not root
	{
		swap(node, Parent(node));
		node = Parent(node);
	}
}

bool MinHeap::isInPlace(int node)

{
	int left = Left(node);
	int right = Right(node);
	if (left != -1 && isSmaller(arr[left],arr[node]))
		return false;
	return!(right != -1 && isSmaller(arr[right],arr[node]));

}

MinHeap::MinHeap(const Array<TreeNode*>&arr)
{
	BuildHeap(arr);
}

TreeNode* MinHeap::deleteMin()
{
	TreeNode* minimum = const_cast<TreeNode*>(min());
	arr[0] = arr[log - 1];
	log--;
	fixheap(0);
	return minimum;

}


void MinHeap::fixheap(int i)
{
	int node = i;
	while (node < log && !isInPlace(node))
	{

		int left = Left(node);
		int right = Right(node);
		int min;
		if (left != -1 && right != -1)
		{
			min = isSmaller(arr[left],arr[right]) ? left : right;

		}
		else
		{
			min = left != -1 ? left : right;
		}
		if (isSmaller(arr[min],arr[node]))
		{
			swap(min, node);
			node = min;
		}


	}

}

void MinHeap::makeEmpty()
{
	log = 0;
}