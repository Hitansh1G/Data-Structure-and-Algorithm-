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

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(root==nullptr) return false;
    else if(root->data==k) return true;
    else{
        if(root->data>k)
        	return searchInBST(root->left,k);
        return searchInBST(root->right,k);
    }
    
}