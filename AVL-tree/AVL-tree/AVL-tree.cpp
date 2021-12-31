#include <iostream>
#include <fstream>

struct Node {
	Node* left, * right, * parent;
	int data;
	int balance;
	Node(int X) : right(nullptr), left(nullptr), parent(nullptr), data(X), balance(0) {}
	~Node() {
		if (left) delete left;
		if (right) delete right;
		left = right = parent = nullptr;
	}
	int level()const {
		int L = (left) ? left->level() : 0;
		int R = (right) ? right->level() : 0;
		return L > R ? L + 1 : R + 1;
	}
};


Node* _RightRotate(Node*& root, Node* b) {
	if (b->balance != -2) return b;
	Node* a = b->left;
	if (a->balance == 1) return b;

	b->left = a->right;
	if (a->right) a->right->parent = b;

	a->parent = b->parent;
	if (b->parent) {
		if (b->parent->left == b)
			b->parent->left = a;
		else
			b->parent->right = a;
	}
	else {
		root = a;
	}

	a->right = b;
	b->parent = a;

	if (a->balance == -1) {
		a->balance = 0; b->balance = 0;
	}
	else {
		a->balance = 1; b->balance = -1;
	}

	return a;
}
Node* _LeftRotate(Node*& root, Node* a) {
	if (a->balance != 2) return a;
	Node* b = a->right;
	if (b->balance == -1) return a;

	a->right = b->left;
	if (b->left) b->left->parent = a;

	b->parent = a->parent;
	if (a->parent) {
		if (a->parent->left == a)
			a->parent->left = b;
		else
			a->parent->right = b;
	}
	else {
		root = b;
	}

	b->left = a;
	a->parent = b;

	if (b->balance == 1) {
		a->balance = 0; b->balance = 0;
	}
	else {
		a->balance = 1; b->balance = -1;
	}
	return b;
}
Node* _DoubleRightRotate(Node*& root, Node* c) {
	if (c->balance != -2) return c;
	Node* a = c->left;
	if (a->balance != 1) return c;
	Node* b = a->right;

	a->right = b->left; if (b->left) b->left->parent = a;
	c->left = b->right; if (b->right) b->right->parent = c;

	b->parent = c->parent;
	if (c->parent) {
		if (c->parent->left == c)
			c->parent->left = b;
		else
			c->parent->right = b;
	}
	else {
		root = b;
	}

	b->left = a;  a->parent = b;
	b->right = c; c->parent = b;

	if (b->balance == 0) {
		a->balance = 0;  c->balance = 0;
	}
	else if (b->balance == 1) {
		a->balance = -1; c->balance = 0;
	}
	else {
		a->balance = 0;  c->balance = 1;
	}
	b->balance = 0;

	return b;

}
Node* _DoubleLeftRotate(Node*& root, Node* a) {
	if (a->balance != 2) return a;
	Node* c = a->right;
	if (c->balance != -1) return a;
	Node* b = c->left;

	a->right = b->left; if (b->left) b->left->parent = a;
	c->left = b->right; if (b->right) b->right->parent = c;

	b->parent = a->parent;
	if (a->parent) {
		if (a->parent->left == a)
			a->parent->left = b;
		else
			a->parent->right = b;
	}
	else {
		root = b;
	}

	b->left = a;  a->parent = b;
	b->right = c; c->parent = b;

	if (b->balance == 0) {
		a->balance = 0;  c->balance = 0;
	}
	else if (b->balance == 1) {
		a->balance = -1; c->balance = 0;
	}
	else {
		a->balance = 0;  c->balance = 1;
	}
	b->balance = 0;
	return b;
}

Node* findEl(Node* root, int X) {
	Node* now = root;
	while (now) {
		if (X == now->data) break;
		if (X < now->data) now = now->left;
		else now = now->right;
	}
	return now;
}

void insert(Node*& root, int X, int& count) {
	++count;
	if (root == nullptr) {
		root = new Node(X);
		return;
	}
	Node* now, * p;
	bool toLeft;
	now = root;
	do {
		p = now;
		if (X < now->data) {
			now = now->left; toLeft = true;
		}
		else {
			now = now->right; toLeft = false;
		}
	} while (now);
	now = new Node(X);
	if (toLeft) p->left = now; else p->right = now;
	now->parent = p;

	// восстановление баланса
	do {
		if (now->parent->left == now) now->parent->balance -= 1;
		else now->parent->balance += 1;
		now = now->parent;
		switch (now->balance) {
		case 2:
			if (now->right->balance == -1) now = _DoubleLeftRotate(root, now);
			else now = _LeftRotate(root, now);
			break;
		case -2:
			if (now->left->balance == 1) now = _DoubleRightRotate(root, now);
			else now = _RightRotate(root, now);
			break;
		}
	} while (now != root && now->balance != 0);
}

void erase(Node*& root, Node* pos, int& count) {
	Node* toDelete = pos;
	if (toDelete == nullptr) return;
	Node* Alt;
	if (toDelete->right == nullptr)
		Alt = toDelete->left;
	else if (toDelete->left == nullptr)
		Alt = toDelete->right;
	else {
		Node* now = toDelete->right;
		while (now->left) now = now->left;
		Alt = now;
		if (Alt->parent != toDelete) {
			Alt->parent->left = Alt->right;
			if (Alt->right) Alt->right->parent = Alt->parent;
			Alt->right = toDelete->right;
			toDelete->right->parent = Alt;
		}
		Alt->left = toDelete->left;
		toDelete->left->parent = Alt;
	}
	Node* notBalanced;
	if (Alt == nullptr) {
		notBalanced = toDelete->parent;
		if (notBalanced) {
			if (notBalanced->left == toDelete) notBalanced->balance += 1;
			else notBalanced->balance -= 1;
		}
	}
	else {
		Alt->balance = toDelete->balance;
		if (Alt->parent == toDelete) {
			notBalanced = Alt;
			if (Alt == toDelete->left) notBalanced->balance += 1;
			else notBalanced->balance -= 1;
		}
		else {
			notBalanced = Alt->parent;
			notBalanced->balance += 1;
		}
	}
	if (toDelete->parent == nullptr) {
		root = Alt;
	}
	else {
		if (toDelete->parent->left == toDelete)
			toDelete->parent->left = Alt;
		else
			toDelete->parent->right = Alt;
	}
	if (Alt != nullptr) {
		Alt->parent = toDelete->parent;
	}

	toDelete->right = nullptr; toDelete->left = nullptr;
	delete toDelete;
	--count;

	// восстановление балансировки
	while (notBalanced) {
		switch (notBalanced->balance) {
		case 2:
			if (notBalanced->right->balance == -1)
				notBalanced = _DoubleLeftRotate(root, notBalanced);
			else
				notBalanced = _LeftRotate(root, notBalanced);
			break;
		case -2:
			if (notBalanced->left->balance == 1)
				notBalanced = _DoubleRightRotate(root, notBalanced);
			else
				notBalanced = _RightRotate(root, notBalanced);
			break;
		}
		if (notBalanced->balance == 1 || notBalanced->balance == -1)
			break;
		if (notBalanced->parent) {
			if (notBalanced->parent->left == notBalanced)
				notBalanced->parent->balance += 1;
			else
				notBalanced->parent->balance -= 1;
		}
		notBalanced = notBalanced->parent;
	}
}

bool find(Node* root, int X) {
	Node* now = root;
	while (now) {
		if (X == now->data) return true;
		if (X < now->data) now = now->left;
		else now = now->right;
	}
	return false;
}

int main() {

	std::ifstream inFile;
	inFile.open("input.txt");
	if (!inFile) {
		std::cout << "Can't open file for reading";
	}
	std::ofstream outFile;
	outFile.open("output.txt");
	if (!outFile) {
		std::cout << "Can't open file for writing";
	}

	int N;
	int count = 0;
	char operation;
	int X;
	inFile >> N;
	Node* root = nullptr;

	for (int i = 0; i < N; ++i) {

		inFile >> operation;
		inFile >> X;
		Node* a = findEl(root, X);

		switch (operation) {
		case '+':
			insert(root, X, count);
			outFile << root->balance << '\n';
			break;

		case '-':
			erase(root, a, count);
			if (root) outFile << root->balance << '\n';
			else outFile << 0 << '\n';

			break;
		case '?':
			outFile << (find(root, X) ? "true" : "false") << '\n';
			break;

		default: 
			std::cout<<"Error in file operation";
			return 1;
		}

	}
	outFile.close();
	inFile.close();
	return 0;
}