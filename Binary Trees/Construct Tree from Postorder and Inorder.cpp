/***********************************************************
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

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    if(postLength!=inLength || postorder==nullptr || inorder==nullptr ||
            postLength==0)
        return nullptr;
    int rootVal = postorder[postLength-1], leftCount, rightCount;
    for(leftCount=0; leftCount<inLength && inorder[leftCount]!=rootVal;
            leftCount++);
    rightCount = postLength-leftCount-1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);
    root->left = buildTree(postorder,leftCount,inorder,leftCount);
    root->right = buildTree(postorder+leftCount,rightCount,inorder+leftCount+1,rightCount);
    return root;
}