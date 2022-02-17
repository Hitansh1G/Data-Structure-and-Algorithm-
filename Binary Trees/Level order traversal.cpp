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
    if(root==nullptr) return;
    queue<BinaryTreeNode<int>*> *inputQ, *outputQ, *temp;
    inputQ = new queue<BinaryTreeNode<int>*>();
    outputQ = new queue<BinaryTreeNode<int>*>();
    inputQ->push(root);
    do{
        while(!inputQ->empty()){
            BinaryTreeNode<int> *curr = inputQ->front();
            inputQ->pop();
            cout << curr->data << ' ';
            if(curr->left!=nullptr)
                outputQ->push(curr->left);
            if(curr->right!=nullptr)
                outputQ->push(curr->right);
        }
        cout << endl;
        temp = inputQ;
        inputQ = outputQ;
        outputQ = temp;
    } 
    while(!inputQ->empty());
    delete inputQ;
    delete outputQ;
}













