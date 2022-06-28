#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Node {
private:
	string data;
	Node* left;
	Node* right;
public:
	Node(string word);
	~Node();
	friend class Tree;
};
class Tree {
private:
	Node* root;
	void addNodeRecur(Node*& parent, string newWord);
	void printNodeOrder(Node*& parent, int level);
	int searchRecur(Node*& parent, string word, int level);
public:
	Tree();
	~Tree();
	void addNode(string word);
	void printTree();
	int searchLevel(string word);
};
