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
#include<bits/stdc++.h>
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    vector<int>* path = new vector<int>;
    while(root!=nullptr){
        path->push_back(root->data);
        if(root->data==data){
            reverse(path->begin(),path->end());
            return path;
        }
        else if(root->data<data)
            root = root->right;
        else
            root = root->left;
    }
    delete path;
    return nullptr;
}