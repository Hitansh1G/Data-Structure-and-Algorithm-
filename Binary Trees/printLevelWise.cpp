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

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==nullptr)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *curr = q.front();
        q.pop();
        int currData=curr->data, left=-1,right=-1;
        if(curr->left!=nullptr){
            left = curr->left->data;
            q.push(curr->left);
        }
        if(curr->right!=nullptr)
        {
            right = curr->right->data;
            q.push(curr->right);
        }
        cout << currData << ":L:" << left << ",R:" << right << endl;
    }
}