#include "Tree.h"

Node::Node(string word) {
	data = word;
	left = NULL;
	right = NULL;
}
Node::~Node() {
	delete left;
	delete right;
}
void Tree::addNodeRecur(Node*& parent, string newWord) {
	if (parent == NULL)
		parent = new Node(newWord);
	else if (newWord < parent->data)
		addNodeRecur(parent->left, newWord);
	else if (newWord > parent->data)
		addNodeRecur(parent->right, newWord);
}
void Tree::printNodeOrder(Node*& parent, int level) {
	char space = ' ';
	char under = '_';
	for (int i = 0; i < level; i++)
		cout << string(3, space) << "|";
	cout << string(2, under);
	if (parent != NULL)
	{
		cout << parent->data << "\n";
		printNodeOrder(parent->right, level + 1);
		printNodeOrder(parent->left, level + 1);
	}
	else
		cout << "\n";
}
int Tree::searchRecur(Node*& parent, string word, int level) {
	if (parent == NULL)
		return -1;
	else if (parent->data == word)
		return level;
	else if (word < parent->data)
		return searchRecur(parent->left, word, level + 1);
	else
		return searchRecur(parent->right, word, level + 1);
}
Tree::Tree() {
	root = NULL;
}
Tree::~Tree() {
	delete root;
}
void Tree::addNode(string word) {
	addNodeRecur(root, word);
}
void Tree::printTree() {
	printNodeOrder(root, 0);
}
int Tree::searchLevel(string word) {
	int n = searchRecur(root, word, 0);
	return n;
}