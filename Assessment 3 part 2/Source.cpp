#include <iostream>
#include <string>
#include <fstream>
#include "BinaryMaxHeap.h"

using namespace std;

void main()
{
	ifstream readFile;
	readFile.open("input-q2a2.txt");

	int numberOfNumbers;
	readFile >> numberOfNumbers;

	BinaryMaxHeap heap;

	for (int i = 0; i < numberOfNumbers; i++)
	{
		heap.showHeap();

		int tempNumber;
		readFile >> tempNumber;

		heap.Insert(tempNumber);

		heap.showHeap();
	}
	

	system("pause");
}