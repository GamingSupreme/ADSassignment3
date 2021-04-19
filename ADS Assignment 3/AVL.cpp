#include "AVL.h"
#include <fstream>

ofstream  writeFile;

int AVL::height(NumberNode* node)
{
    //Start height off at zero
    int h = 0;
    if (node != NULL)
    {
        int leftHeight = height(node->leftChild);
        int rightHeight = height(node->rightChild);

        int maxHeight = max(leftHeight, rightHeight);
        h = maxHeight;
    }
    return h;
}

int AVL::difference(NumberNode* node)
{
    //just incase the tree is empty
    if (node == NULL)
        return 0;

    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);
    int balanceFactor = leftHeight - rightHeight;

    return balanceFactor;
}

NumberNode* AVL::RRrotation(NumberNode* parent)
{
    NumberNode* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;

    return temp;
}

NumberNode* AVL::LLrotation(NumberNode* parent)
{
    NumberNode* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;

    return temp;
}

NumberNode* AVL::LRrotation(NumberNode* parent)
{
    NumberNode* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);

    return LLrotation(parent);
}

NumberNode* AVL::RLrotation(NumberNode* parent)
{
    NumberNode* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);

    return RRrotation(parent);
}

NumberNode* AVL::balance(NumberNode* parent)
{
    //First get the balance factor which we get from both sides of the tree
    int balanceFactor = difference(parent);
    
    if (balanceFactor > 1)
    {
        if (difference(parent->leftChild) > 0)
        {
            //this means that the left side isnt balanced
            parent = LLrotation(parent);
        }
        else
        {
            //Otherwise the right side is unbalanced
            parent = LRrotation(parent);
        }
    }

    else if (balanceFactor < -1)
    {
        if (difference(parent->rightChild) > 0)
        {
            //same as before, this means the left side is unbalanced
            parent = RLrotation(parent);
        }
        else
        {
            //right must be unbalanced
            parent = RRrotation(parent);
        }
    }
    return parent;
}

NumberNode* AVL::AVLinsert(NumberNode* parent, NumberNode* newNumber)
{
    //incase tree is empty this will be the new parent
    if (parent == NULL)
    {
        parent = newNumber;
        return parent;
    }

    if (newNumber->Number < parent->Number)
    {
        parent->leftChild = AVLinsert(parent->leftChild, newNumber);
        parent = balance(parent);
    }
    else
    {
        parent->rightChild = AVLinsert(parent->rightChild, newNumber);
        parent = balance(parent);
    }
}

void AVL::insert(NumberNode* newNumber)
{
    root = AVLinsert(root, newNumber);
} 

void AVL::breadthFirstTraversal(NumberNode* p)
{
    writeFile.open("output-a1q2.txt");
    //incase tree is empty
    if (root == NULL) return;

    queue<NumberLevelNode> numberQ;

    numberQ.push(NumberLevelNode(root, 0));
    int previousLevel = -1;

    while (numberQ.empty() == false)
    {
        NumberLevelNode node = numberQ.front();
        if (node.level != previousLevel)
        {
            writeFile << endl;
            writeFile << node.level << ": ";
            previousLevel = node.level;
        }
        writeFile << node.number->Number << " ";
        numberQ.pop();

        if (node.number->leftChild != NULL)
            numberQ.push(NumberLevelNode(node.number->leftChild, node.level + 1));

        if (node.number->rightChild != NULL)
            numberQ.push(NumberLevelNode(node.number->rightChild, node.level + 1));

    }

}

void AVL::inOrderTraversal(NumberNode* current)
{
    if (current != NULL)
    {
        inOrderTraversal(current->leftChild);
        cout << current->Number << endl;
        inOrderTraversal(current->rightChild);
    }
}
