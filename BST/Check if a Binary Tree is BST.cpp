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
#include<bits/stdc++.h>
bool areElementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if(root==nullptr) return true;
    if(root->data<k1 || k2<root->data) return false;
    if(!areElementsInRangeK1K2(root->left, k1, k2)) return false;
    if(!areElementsInRangeK1K2(root->right, k1, k2)) return false;
    return true;
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==nullptr) return true;
    if(!isBST(root->left)) return false;
    if(!isBST(root->right)) return false;
    if(!areElementsInRangeK1K2(root->left, INT_MIN, root->data-1)) return false;
    if(!areElementsInRangeK1K2(root->right, root->data, INT_MAX)) return false;
    return true;
}