#include<iostream>
using namespace std;
struct Node {
	char ch;
	Node* left;
	Node* right;
	Node* par;
	Node(char ch) {
		this->ch = ch;
		left = right = par = NULL;
	}
};
Node* find_node;
class Tree {
public:
	Node* root;
	Tree() {
		root = NULL;
	}
	void searchNode(Node* node, char find_ch) {
		if (node == NULL)
			return;
		if (node->ch == find_ch) {
			find_node = node;
			return;
		}
		searchNode(node->left, find_ch);
		searchNode(node->right, find_ch);
	}
	void insert(char parent, char left, char right) {
		searchNode(root, parent);
		if (left == '.' && right != '.') {
			find_node->right = new Node(right);
		}
		else if (left != '.' && right == '.')
			find_node->left = new Node(left);
		else if (left == '.' && right == '.')
			return;
		else {
			find_node->left = new Node(left);
			find_node->right = new Node(right);
		}
	}
	void pre(Node *node) {
		if (node == NULL)
			return;
		cout << node->ch;
		pre(node->left);
		pre(node->right);
	}
	void inorder(Node* node) {
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->ch;
		inorder(node->right);
	}
	void post(Node* node) {
		if (node == NULL)
			return;
		post(node->left);
		post(node->right);
		cout << node->ch;
	}
};
int main() {
	int T;
	cin >> T;
	Tree tree;
	tree.root = new Node('A');
	while (T--) {
		char par, left, right;
		cin >> par >> left >> right;
		tree.insert(par, left, right);
	}
	tree.pre(tree.root);
	cout << "\n";
	tree.inorder(tree.root);
	cout << "\n";
	tree.post(tree.root);
}