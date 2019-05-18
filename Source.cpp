#include <vector>
#include <iostream>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST& insert(int val) {
        // Write your code here.
        // Do not edit the return statement of this method.
        //BST* newBST = new BST(val);
        BST* currNode = this;

        while (true)
        {
            if (currNode->value > val)
            {
                if (!currNode->left)
                {
                    currNode->left = new BST(val);
                    break;
                }
                else
                {
                    currNode = currNode->left;
                }
            }
            else
            {
                if (!currNode->right)
                {
                    currNode->right = new BST(val);
                    break;
                }
                else
                {
                    currNode = currNode->right;
                }
            }
        }

        return *this;
    }

    bool contains(int val) {
        // Write your code here.

        if (this && this->value == val)
        {
            return true;
        }
        else if (this->left && this->value >= val)
        {
            return this->left->contains(val);
        }
        else if (this->right)
        {
            return this->right->contains(val);
        }

        return false;
    }

    BST& remove(int val, BST* parentNode = nullptr) {
    // Write your code here.
    // Do not edit the return statement of this method.
        BST * currNode = this;
        while (currNode != nullptr)
        {
            if (val < currNode->value)
            {
                parentNode = currNode;
                currNode = currNode->left;
            }
            else if (val > currNode->value)
            {
                parentNode = currNode;
                currNode = currNode->right;
            }
            else
            {
                if (currNode->left != nullptr && currNode->right != nullptr)
                {
                    currNode->value = currNode->right->getMinimum();
                    currNode->right->remove(currNode->value, currNode);
                }
                else if (parentNode == nullptr)
                {
                    if (currNode->left != nullptr)
                    {
                        currNode->value = currNode->left->value;
                        currNode->right = currNode->left->right;
                        currNode->left = currNode->left->left;
                    }
                    else if (currNode->right != nullptr)
                    {
                        currNode->value = currNode->right->value;
                        currNode->left = currNode->right->left;
                        currNode->right = currNode->right->right;
                    }
                    else
                    {
                        currNode->value = 0;
                    }
                }
                else if(parentNode->left == currNode)
                {
                    parentNode->left = currNode->left != nullptr ? currNode->left : currNode->right;
                }
                else if (parentNode->right == currNode)
                {
                    parentNode->right = currNode->left != nullptr ? currNode->left : currNode->right;
                }
                break;
            }
        }
        return *this;
    }

    int getMinimum()
    {
        BST* currentNode = this;
        while (currentNode && currentNode->left)
        {
            currentNode = currentNode->left;
        }

        return currentNode->value;
    }
};

void inorder(BST* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

int main()
{

    BST* newBST = new BST(10);
    newBST->insert(5).insert(7).insert(2);
    /*newBST->insert(11);
    newBST->insert(5);
    newBST->insert(15);
    newBST->insert(23);
    newBST->insert(50);
    newBST->insert(2);*/
    
    inorder(newBST);
    cout << endl;
    newBST->remove(10);
 
    inorder(newBST);

    getchar();
    return 0;
}
