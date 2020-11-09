#include <iostream>
#include <vector>

using namespace std;

class node {
	public:
	node *parent;
	char color;
	vector <node*> children;

	node(node* par) {
		parent = par;
	}

};

node* createTree (node *par) {
	node *elem;
	char ch;
	while (cin >> ch) {
		switch (ch) {
			case '(':
				elem = new node(par);
				break;
			case ',':
				elem->children.push_back(createTree(elem));
				break;
			case 'w':
				elem->color = 'w';
				break;
			case 'g':
				elem->color = 'g';
				break;
			case 'b':
				elem->color = 'b';
				break;
			case ')':
				return elem;
		}
	}
}

void printTree(node *elem) {
	cout << '(' << elem->color;
	for (int i=0; i<elem->children.size(); i++) {
		cout << ',';
		printTree(elem->children[i]);
	}
	cout << ')';
}

int countTree (node *elem, bool black) {
	int count=0;
	if (elem->color == 'b') black = true;
	if (black && elem->color == 'w') count++;
	for (int i=0; i<elem->children.size(); i++) {
		count += countTree(elem->children[i], black);
	}
	return count;
}

int main () {

	char ch;

	node *root;

	root = createTree(NULL);

	cout << countTree(root, false);

	return 0;
}
