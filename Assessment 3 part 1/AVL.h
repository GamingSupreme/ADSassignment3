#pragma once
#include <queue>
#include "NumberNode.h"
#include <iostream>
#include <string>

using namespace std;

class NumberLevelNode
{
public:
	NumberNode* number;
	int level;

	NumberLevelNode(NumberNode* number, int level)
	{
		this->number = number;
		this->level = level;
	}
};

class AVL
{
public:
	NumberNode* root = NULL;
	void insert(NumberNode* newStudent);

	int height(NumberNode* node);
	int difference(NumberNode* node);

	//All rotation functions
	NumberNode* RRrotation(NumberNode* parent);
	NumberNode* LLrotation(NumberNode* parent);
	NumberNode* LRrotation(NumberNode* parent);
	NumberNode* RLrotation(NumberNode* parent);

	//Balance Function
	NumberNode* balance(NumberNode* parent);

	//Insert Function
	NumberNode* AVLinsert(NumberNode* parent, NumberNode* newNumber);

	void breadthFirstTraversal(NumberNode* p);
};

