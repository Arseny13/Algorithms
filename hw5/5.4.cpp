#include <stdio.h>
#include <iostream>
using namespace std;

struct Tree {
	Tree *children[2];
	unsigned long long value;
	Tree() {
		children[0] = children[1] = nullptr;
		value = 0;
	}
};

void insert(Tree *t, unsigned long long A) {
	Tree *curr = t;
	for(int i = 31; i >= 0; --i) {
		int index = (A>>i)&1u;
		if(curr->children[index])
			curr = curr->children[index];
		else {
			curr->children[index] = new Tree;
			curr = curr->children[index];
		}
	}
	curr->value = A;
}

bool remove_elem(Tree *t, unsigned long long A, int height) {
	Tree *curr = t;
	if(height == 0) {
		delete curr;
		return true;
	}
	int index = (A>>(height-1))&1u;
	if(curr == nullptr)
		return false;
	if(remove_elem(curr->children[index], A, height-1))
		if(curr->children[index ? 0 : 1]) {
			curr->children[index] = nullptr;
			return false;
		}
		else {
			delete curr;
			return true;
		}
	return false;
}

void remove(Tree *t, unsigned long long A, int height) {
	if(remove_elem(t->children[A>>height-1], A, height-1))
		t->children[A>>height-1] = nullptr;
}

unsigned long long findMax(Tree *t, unsigned long long Q) {
	Tree *curr = t;
	for(int i = 31; i >= 0; --i) {
		int index = (Q>>i)&1u ? 0 : 1;
		if(curr->children[index])
			curr = curr->children[index];
		else
			curr = curr->children[index ? 0 : 1];
	}
	return curr->value;
}


int main() {
	unsigned long long N;
	unsigned long long index=0, argument=0;
	cin >> N;
	Tree *t = new Tree;
	for(unsigned long long i = 0; i < N; ++i) {
        scanf("%lu %lu",&index,&argument);
		switch(index) {
			case 1:
				insert(t, argument);
				break;
			case 2:
				remove(t, argument, 32);
				break;
			case 3:
				cout << findMax(t, argument) << '\n';
				break;
		}
	}
	return 0;
}
