#include "Tree.h"
#include "Function.h"

int main()
{
	cout << "To stop writing lines to the tree - press ENTER\n\n";
	vector <string> arr = inputArr();

	cout << "\nEntered words:\n";
	printArr(arr);

	Tree tree;
	addToTree(arr, tree);

	cout << "\nThe tree:\n";
	tree.printTree();
	findWordnLevel(tree);

	cin.ignore(2);
}