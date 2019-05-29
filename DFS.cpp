using namespace std;

#include <iostream>

class NodeElement {
public:
	int value;
	NodeElement* left;
	NodeElement* right;
	void DFS() {
		if (left) { (*left).DFS();}
		if (right) { (*right).DFS(); }
		cout << value << endl;
	}
};


// test
int main()
{
	NodeElement NodeElement1{ 1 };
	NodeElement NodeElement2{ 2, &NodeElement1 };
	NodeElement NodeElement4{ 4 };
	NodeElement NodeElement3{ 3, &NodeElement2, &NodeElement4};
	NodeElement3.DFS();
	return 0;
}
