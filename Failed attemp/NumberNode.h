#pragma once
#include <iostream>
#include <string>

using namespace std;

class NumberNode
{
public:
	int Number;
	NumberNode* leftChild;
	NumberNode* rightChild;

	NumberNode(int Number);
};

