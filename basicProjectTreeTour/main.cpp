#include <iostream>
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int d) :data(d), left(NULL), right(NULL) { std::cout << "Creating Object Node" << '\n'; }
	~Node() { std::cout << "Deleting Object Node" << '\n'; }
};
typedef struct Node* TREE;
TREE createNode(int d) {
	TREE newNode = new Node(d);
	return newNode;
}
void insertNode(TREE& tree, int d) {
	if (tree == NULL)tree = createNode(d);
	else if (d < tree->data)insertNode(tree->left, d);
	else if (d > tree->data)insertNode(tree->right, d);
}
void printTree(TREE tree, int i) {
	if (tree == NULL)return;
	printTree(tree->right, i + 1);
	for (int ii = 0; ii < i; ii++)std::cout << "    ";
	std::cout << tree->data << '\n';
	printTree(tree->left, i + 1);
}
void preOrder(TREE tree) {
	if (tree) {
		std::cout << tree->data << ' ';
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
void inOrder(TREE tree) {
	if (tree) {
		inOrder(tree->left);
		std::cout << tree->data << ' ';
		inOrder(tree->right);
	}
}
void postOrder(TREE tree) {
	if (tree) {
		postOrder(tree->left);
		postOrder(tree->right);
		std::cout << tree->data << ' ';
	}
}
int main() {
	TREE t01 = NULL;
	insertNode(t01, 50);
	insertNode(t01, 40);
	insertNode(t01, 60);
	insertNode(t01, 55);
	insertNode(t01, 45);
	insertNode(t01, 53);
	//std::cout<<t01->data<<'\n';
	printTree(t01, 0);
	preOrder(t01);
	std::cout << '\n';
	inOrder(t01);
	std::cout << '\n';
	postOrder(t01);
	std::cout << '\n';
	std::cout << "Change Test";
	delete t01;
	return 0;
}