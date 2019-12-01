#include "Header.h"
using namespace std;

struct TrieNode
{
	vector<TrieNode*> children;
	bool isEndOfWord;
	int count;
};

TrieNode* newNode()
{
	TrieNode* node = new TrieNode;

	node->isEndOfWord = false;
	node->count = 0;
	for (int i = 0; i < 26; ++i)
	{
		node->children.push_back(nullptr);
	}

	return node;
}
void insertUtils(TrieNode* root, string &word)
{
	auto pCrawl = root;
	for (char c : word)
	{
		int index = c - 'a';
		if (!pCrawl->children[index])
		{
			pCrawl->children[index] = newNode();
		}
		pCrawl->children[index]->count++;
		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}

void insert(TrieNode* root, string &word)
{
	if (!root)
	{
		root = newNode();
	}

	insertUtils(root, word);
}

bool search(TrieNode* root, const string& word)
{
	if (!root)return false;
	auto pCrawl = root;

	for (char c : word)
	{
		int index = c - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl && pCrawl->isEndOfWord);
}

vector<string> prefix(TrieNode* root, vector<string>& A)
{
	vector<string> result;
	for (string& s : A)
	{
		auto pCrawl = root;
		string pre = "";

		for (char c : s)
		{
			int index = c - 'a';
			pre = pre + c;
			if (pCrawl->children[index]->count == 1)
			{
				result.push_back(pre);
				break;
			}
			if (pre == s)
			{
				result.push_back(pre);
				break;
			}
			pCrawl = pCrawl->children[index];
		}
	}

	return result;
}

int main()
{
	vector<string> keys = { "zebra", "dog", "duck", "dove" };
	TrieNode* root = newNode();

	for (auto& s : keys)
	{
		insert(root, s);
	}

	search(root, "the") ? cout << "Yes\n" :
		cout << "No\n";
	search(root, "these") ? cout << "Yes\n" :
		cout << "No\n";

	auto ans = prefix(root, keys);
	return 0;
}