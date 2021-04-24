#include "BinaryMaxHeap.h"
#include <fstream>

ofstream writeFile;

int BinaryMaxHeap::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

int BinaryMaxHeap::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

int BinaryMaxHeap::parentIndex(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return parent;
}

void BinaryMaxHeap::heapifyup(int index)
{
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].number > heap[parentIndex(index)].number)
    {
        Number temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;

        heapifyup(parentIndex(index));
    }
}

void BinaryMaxHeap::heapifydown(int index)
{
    int childL = leftChildIndex(index);
    int childR = rightChildIndex(index);

    int childIndex = childL;

    if (childL >= 0 && childR >= 0 && heap[childR].number > heap[childL].number)
    {
        childIndex = childR;
    }

    if (childIndex > 0 && heap[index].number < heap[childIndex].number)
    {
        Number temp = heap[index];
        heap[index] = heap[childIndex];
        heap[childIndex] = temp;

        heapifydown(childIndex);
    }
}

void BinaryMaxHeap::Insert(Number number)
{
    heap.push_back(number);
    //heapifyup(heap.size() - 1);
}

void BinaryMaxHeap::showHeap()
{
    writeFile.open("output-q2-a2.txt");
    for (Number n : heap)
    {
        writeFile << n.number << " ";
    }
    writeFile.close();
}
