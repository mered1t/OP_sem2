#include "Function.h"
#include "Tree.h"

vector <string> inputArr()
{
	vector <string> arr;
	arr = enterWords();
	return arr;
}
void printArr(vector <string> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}
vector <string> enterWords()
{ 
	vector <string> arr;
	cout << "Enter words:\n";
	string str;
	for (int i = 1; ; i++)
	{
		cout << i << ") ";
		getline(cin, str);
		if (str == "") { break;}
		arr.push_back(str);
	}
	return arr;
}
string enterWordtoSearch()
{
	string word;
	cout << "\nEnter word to search: ";
	cin >> word;
	while (word.length() < 1)
	{
		cout << "Enter correct word:";
		cin >> word;
	}

	return word;
}

bool isNumber(const std::string& word) {
	for (char i : word) {
		if (!isdigit(i)) return false;
	}
	return true;
}

void addToTree(vector<string> arr, Tree &tree)
{
	for (int i = 0; i < arr.size(); i++)
		tree.addNode(arr[i]);
}

void findWordnLevel(Tree &tree)
{
	string word = enterWordtoSearch();
	int level = tree.searchLevel(word);
	if (level != -1)
		cout << "\nlevel of word '" << word << "' = " << level + 1 << "\n";
	else
		cout << "\nThere is no word '" << word << "'\n";
}

