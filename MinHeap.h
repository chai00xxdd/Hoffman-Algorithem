#pragma once
#include"TreeNode.h"
#include"Array.h"
class MinHeap
{
	
private:
	
	Array<TreeNode*> arr;
	int log=0;
	void fixheap(int i);
	//the function fix the heap after insert operation
	void fixInsert();
	void swap(int i, int j)
	{
		TreeNode* temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	//return the left child of node or -1 if null
	 int Left(int node)
	{
		int left = node * 2 + 1;
		return left < log ? left : -1;
	}
	 //return the right child of node or -1 if null
	 int Right(int node)
	{
		int right = node * 2 + 2;
		return right < log ? right : -1;
	}
	 //the function get a node and return true
	 //if node is valid <--->node smaller then his sons
	 bool isInPlace(int node);
	 //return the parent of node
	static int Parent(int node) 
	{
		if (node == 0)
			return -1;
		return (node - 1) / 2;
	}
	//the function return true if t1 frequency 
	// less then t2 prequency
	static bool isSmaller(TreeNode*t1, TreeNode*t2);
public:
	
	//ctors dtors
	MinHeap(int phy=0);
	MinHeap(const MinHeap&other);
	//constructor the heap by floyd algorithem
	MinHeap(const Array<TreeNode*>&arr);
	// build the heap by floyd algorithem
	void BuildHeap(const Array<TreeNode*>&arr);
	~MinHeap();
	//insert a new data to the heap and fix it
	bool insert( TreeNode*);
	//return the minimum of the heap
	 const TreeNode* min() { return arr[0]; }
	 //delete the min of the heap and returns it
	 TreeNode* deleteMin();
	 //clear the heap
	void makeEmpty();

	//data length functions
	bool isEmpty()const { return log == 0; }
	bool isFull()const { return log == arr.length(); }
	int length()const { return log; }
	//operators
	void operator=(const MinHeap&other) = delete;
};




