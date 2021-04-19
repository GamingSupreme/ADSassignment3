#include "AVL.h"

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

int AVL::difference(NumberNode* Node)
{
    //just incase the tree is empty
    if (Node == NULL)
        return 0;

    int leftHeight = height(Node->leftChild);
    int rightHeight = height(Node->rightChild);
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

NumberNode* AVL::insert(NumberNode* parent, NumberNode* newNumber)
{
    //incase tree is empty this will be the new parent
    if (parent == NULL)
    {
        parent = newNumber;
        return parent;
    }

    if (newNumber->Number < parent->Number)
    {
        parent->leftChild = insert(parent->leftChild, newNumber);
        parent = balance(parent);
    }
    else
    {
        parent->rightChild = insert(parent->rightChild, newNumber);
        parent = balance(parent);
    }
}

void AVL::breadthFirstTraversal(NumberNode* p)
{
    //incase tree is empty
    if (root == NULL) return;

    queue<NumberLevelNode> numberQ;

    numberQ.push(NumberLevelNode(root, 0));
    int previousLevel = -1;

    while (numberQ.empty() == false)
    {

    }

}
