struct BinaryTreeNode {
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};
//typedef struct BinaryTreeNode *BinaryTreeNodePtr;

int main() {
	BinaryTreeNode *n = new BinaryTreeNode;
	n -> data = 123;
	
	cout << "BinaryTreeNode type: data == " << n -> data << endl;
	
	delete n;
	
	return 0
}