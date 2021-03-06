/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(input==nullptr || n<=0) return nullptr;
    int rootIndex = (n-1)/2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[rootIndex]);
    root->left = constructTree(input,rootIndex);
    root->right = constructTree(input+rootIndex+1,n-rootIndex-1);
    return root;
}