#include<iostream>

class BSTree {
private:
	struct Node {
		int value;
		Node* right;
		Node* left;

		Node(int val) : value(val), right(nullptr), left(nullptr) {}
	} *root;
public:
	BSTree();
	BSTree(const BSTree& other);
	~BSTree();

	void print();
}; 




    btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}