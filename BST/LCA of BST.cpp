/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    /* Given a BST and an integer k. Find if the integer k is present in given
     * BST or not. Return the node with data k if it is present, return null
     * otherwise. Assume that BST contains all unique elements. */
    if(root==nullptr) return nullptr;
    if(root->data==k) return root;
    BinaryTreeNode<int>* left = searchInBST(root->left, k);
    if(left!=nullptr) return left;
    BinaryTreeNode<int>* right = searchInBST(root->right, k);
    return right;
}
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(root==nullptr) return -1;
    if(val1>val2){
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }
    BinaryTreeNode <int>* node1 = searchInBST(root, val1);
    BinaryTreeNode <int>* node2 = searchInBST(root, val2);
    if(node1==nullptr){
        if(node2==nullptr) return -1;
        else return node2->data;
    }
    if(node2==nullptr)
        return node1->data;
    if(node1 == node2) return node1->data;

    BinaryTreeNode <int>* curr = root;
    while(curr != nullptr){
        if(val1 <= curr->data && curr->data <= val2) return curr->data;
        if(val2 < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return -1;
}