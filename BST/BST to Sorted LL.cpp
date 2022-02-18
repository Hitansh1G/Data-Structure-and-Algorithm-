/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==nullptr) 
        return nullptr;
    Node<int> *list = constructLinkedList(root->left);
    Node<int> *curr = new Node<int>(root->data);
    curr->next = constructLinkedList(root->right);
    if(list==nullptr) 
        return curr;
    Node<int> *ptr = list;
    while(ptr->next!=nullptr)
        ptr = ptr->next;
    ptr->next = curr;
    return list;
}