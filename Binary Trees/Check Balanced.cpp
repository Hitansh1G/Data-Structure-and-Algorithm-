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
int depth(BinaryTreeNode<int> *root) {
    if(root==nullptr) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return max(left,right)+1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==nullptr) return true;
    int left = depth(root->left);
    int right = depth(root->right);
    int diff = abs(left-right);
    if(diff>1) return false;
    if(!isBalanced(root->left)) return false;
    if(!isBalanced(root->right)) return false;
    return true;
}