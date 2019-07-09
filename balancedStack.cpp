#include <stack>
#include <string>

using namespace std;

bool balancedBrackets(string str) {
	// Write your code here.
	stack <char> s;
	char x;
	for (char c : str)
	{

		if (c == '(' || c == '{' || c == '[')
		{
			s.push(c);
			continue;
		}

		if (s.empty())return false;
		switch (c)
		{
		case ')':

			// Store the top element in a 
			x = s.top();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			// Store the top element in b 
			x = s.top();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			// Store the top element in c 
			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}

	return s.empty();
}

int main()
{
	string s = "[{()}]";
	bool result = balancedBrackets(s);

	return 0;

}
