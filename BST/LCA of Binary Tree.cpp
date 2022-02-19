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
BinaryTreeNode<int>* searchInBinaryTree(BinaryTreeNode<int> *root , int x){
    if(root==nullptr) return nullptr;
    if(root->data == x) return root;
    BinaryTreeNode<int>* result = searchInBinaryTree(root->left, x);
    if(result!=nullptr) return result;
    result = searchInBinaryTree(root->right, x);
    return result;
}
int getLCA(BinaryTreeNode <int>* root , int val1, int val2) {
    // Write your code here
    if(root==nullptr) return -1;
    BinaryTreeNode <int>* node1 = searchInBinaryTree(root, val1);
    BinaryTreeNode <int>* node2 = searchInBinaryTree(root, val2);
    if(node1==nullptr)
    {
        if(node2==nullptr) return -1;
        else return node2->data;
    }
    // node1 is not null
    if(node2==nullptr)
        return node1->data;
    // node2 is not null
    if(node1 == node2) return node1->data;
    /* Here we are sure that we have two distinct nodes present in the tree. Now,
     * we can start from root and traverse the tree untill we get the LCA Node */
    BinaryTreeNode <int>* curr = root;
    while(curr != nullptr)
    {
        /* If both nodes are present in left tree */
        node1 = searchInBinaryTree(curr->left, val1);
        node2 = searchInBinaryTree(curr->left, val2);
        if(node1!=nullptr && node2!=nullptr)
        {
            curr = curr->left;
            continue;
        }
        /* If both nodes are present in right tree */
        node1 = searchInBinaryTree(curr->right, val1);
        node2 = searchInBinaryTree(curr->right, val2);
        if(node1!=nullptr && node2!=nullptr)
        {
            curr = curr->right;
            continue;
        }
        return curr->data;
    }
    /* This code should never be executed */
    return -1;
} 