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

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    if(root==nullptr) return;
    elementsInRangeK1K2(root->left, k1, k2);
    if(k1<=root->data && root->data<=k2)
        cout<< root->data << ' ';
    elementsInRangeK1K2(root->right, k1, k2);
}