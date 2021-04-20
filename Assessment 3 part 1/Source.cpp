#include <iostream>
#include <string>
#include <fstream>
#include "AVL.h"

using namespace std;

void main()
{
	ifstream readFile;
	readFile.open("input-q1a2.txt");

	AVL avl1;

	int numberOfNumbers;
	readFile >> numberOfNumbers;
	int currentNumber = 0;

	for (int i = 0; i < numberOfNumbers; i++)
	{
		readFile >> currentNumber;
		avl1.insert(new NumberNode(currentNumber));
	}

	avl1.breadthFirstTraversal(avl1.root);

	system("pause");
}