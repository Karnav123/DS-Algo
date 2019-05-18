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
		if (value > val)
		{
			if (left != nullptr)
			{
				left->insert(val);
			}
			else
			{
				BST* newBST = new BST(val);
				left = newBST;
			}
		}
		else
		{
			if (right != nullptr)
			{
				right->insert(val);
			}
			else
			{
				BST* newBST = new BST(val);
				right = newBST;
			}
		}
		return *this;
	}

	bool contains(int val) {
		// Write your code here.

		if (val < value)
		{
			if (left == nullptr)
			{
				return false;
			}
			else
			{
				left->contains(val);
			}
		}
		else if (val < value)
		{
			if (right == nullptr)
			{
				return false;
			}
			else
			{
				right->contains(val);
			}
		}
		else
		{
			return true;
		}
	}

	BST& remove(int val, BST* parentNode = nullptr) {
		// Write your code here.
		// Do not edit the return statement of this method.
		if (val < value)
		{
			if (left != nullptr)
			{
				left->remove(val, this);
			}
		}
		else if (val > value)
		{
			if (right != nullptr)
			{
				right->remove(val, this);
			}
		}
		else
		{
			if (left != nullptr && right != nullptr)
			{
				value = right->getMinimum();
				right->remove(value, this);
			}
			else if (parentNode == nullptr)
			{
				if (left != nullptr)
				{
					value = left->value;
					right = left->right;
					left = left->left;
				}
				else if (right != nullptr)
				{
					value = right->value;
					left = right->left;
					right = right->right;
				}
				else
				{
					value = 0;
				}
			}
			else if (parentNode->left == this)
			{
				parentNode->left = left != nullptr ? left : right;
			}
			else if (parentNode->right == this)
			{
				parentNode->right = left != nullptr ? left : right;
			}
		}
		return *this;
	}

	bool validateBst(int min = INT_MIN, int max = INT_MAX) {
		if (this->value < min || this->value >= max)
		{
			return false;
		}
		else if (this->left != nullptr && !validateBst(min, this->value))
		{
			return false;
		}
		else if (this->right != nullptr && !validateBst(this->value, max))
		{
			return false;
		}
		return true;
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