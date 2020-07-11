
#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>

struct Node {
	int x;
	Node *left, *right;
};

void addNode(std::vector<int>::iterator it, std::vector<bool>::iterator itb, Node*& Tree, std::vector<int>::iterator beg, std::vector<int>::iterator end) {
	Tree = new Node;
	Tree->x = *it;
	*itb = true;
	Tree->left = Tree->right = nullptr;
	if (it != beg && *(itb - 1) == false) 
		addNode(it - 1, itb - 1, Tree->left, beg, end);
	
	if ((it + 1) != end && *(itb + 1) == false) 
		addNode(it + 1, itb + 1, Tree->right, beg, end);
	

}

void addN(std::vector<int>::iterator it, Node*& Tree, int i, int size, std::vector<bool>::iterator itb, std::vector<int>::iterator beg, std::vector<int>::iterator end) {
	int step = size / (2 * i);

	if (step!=0) {
		if (Tree == nullptr) {
			Tree = new Node;
			Tree->x = *it;
			*itb = true;
			Tree->left = Tree->right = nullptr;
			i = i * 2;
			addN(it - step,Tree->left, i, size, itb-step,beg,end);
			addN(it + step, Tree->right, i, size, itb+step, beg, end);
		}
	}
	else {
		Tree = new Node;
		Tree->x = *it;
		*itb = true;
		Tree->left = Tree->right = nullptr;

		if (*(itb - 1) == false)
				addNode(it - 1, itb - 1, Tree->left, beg, end);

		if (*(itb + 1) == false)
				addNode(it + 1, itb + 1, Tree->right, beg, end);

	}

	}



void show(Node *&Tree) {
	
	if (Tree != nullptr) {
		if ((Tree->right!=nullptr) || (Tree->left!=nullptr)) {
			std::cout << "(";
			show(Tree->left);
			std::cout <<","<< Tree->x<<",";
			show(Tree->right);
			std::cout << ")";
		}
		else
			std::cout << "(_"<< Tree->x <<"_)";
		
	
	}
}


int main()
{
	int v;
	Node *MyTree=NULL;
	std::vector<int> startTreeV;

	while(std::cin>> v)
		startTreeV.push_back(v);

	std::vector<bool> check(startTreeV.size(), false);
	std::sort(startTreeV.begin(), startTreeV.end(), [](int f, int s) {return f < s; });

	std::vector<int>::iterator it= startTreeV.begin() + startTreeV.size()/2;
	std::vector<bool>::iterator itb = check.begin() + check.size() / 2;

	int size = startTreeV.size();
	std::vector<int>::iterator beg = startTreeV.begin();
	 std::vector<int>::iterator end = startTreeV.end();

	addN(it, *&MyTree, 2, size, itb, beg, end);
	show(MyTree);

	return 0;
}
