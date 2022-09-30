#include<iostream>

class BSTree {
private:
	struct Node {
		int value;
		Node* right;
		Node* left;

		Node(int val) : value(val), right(nullptr), left(nullptr) {}
		Node() : value(0), right(nullptr), left(nullptr) {}
	} *root;
public:
	BSTree();
	BSTree(const BSTree& other);
	~BSTree();

	void print(Node *cur);

	void destroy(Node* cur);
	void add(int value, Node* cur);
	void add(int value);
}; 

BSTree::BSTree() {
	root = nullptr;
}

BSTree::~BSTree() {
	destroy(root);
}

void BSTree::destroy(Node* cur) {
	if (cur) {
		destroy(cur->left);
		destroy(cur->right);
		delete cur;
	}
}

void BSTree::print(Node *cur) {
	if (cur) {
		print(cur->left);
		std::cout << cur->value<<' ';
		print(cur->right);
	}

}
void BSTree::add(int value, Node* cur) {

	if (value <= cur->value) {
		if (cur->left) {
			add(value, cur->left);
		}
		else {
			cur->left = new Node;
			cur->left->value = value;
			cur->left->left = nullptr;
			cur->left->right = nullptr;
		}
	}
	else if (value > cur->value) {
		if (cur->right) {
			add(value, cur->right);
		}
		else {
			cur->right = new Node;
			cur->right->value = value;
			cur->right->right = nullptr;
			cur->right->left = nullptr;
		}
	}

}
void BSTree::add(int value) {
	if (root) {
		add(value, root);
	}
	else {
		root = new Node;
		root->value = value;
		root->left = nullptr;
		root->right = nullptr;
	}
}

int main() {



	return 0;
}