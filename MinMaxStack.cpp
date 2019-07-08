#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
	vector<unordered_map<string, int>> minMaxStack;
	vector<int> stack;
	int peek() {
		// Write your code here.
		return stack[stack.size() - 1];
	}

	int pop() {
		// Write your code here.
		minMaxStack.pop_back();
		int result = peek();
		stack.pop_back();

		return result;
	}

	void push(int number) {
		// Write your code here.
		unordered_map<string, int> newMinMaxStack = { { "Min" , number}, {"Max" , number } };

		if (minMaxStack.size())
		{
			auto lastMinMax = minMaxStack[minMaxStack.size() - 1];
			newMinMaxStack["Min"] = min(lastMinMax["Min"], number);
			newMinMaxStack["Max"] = max(lastMinMax["Max"], number);

			minMaxStack.push_back(newMinMaxStack);
		}

		stack.push_back(number);
	}

	int getMin() {
		// Write your code here.
		return minMaxStack[minMaxStack.size() - 1]["Min"];
	}

	int getMax() {
		// Write your code here.
		return  minMaxStack[minMaxStack.size() - 1]["Max"];
	}
};

