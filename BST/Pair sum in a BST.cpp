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
#include <bits/stdc++.h>
int k=0;

void convert (BinaryTreeNode<int> *root,int *arr){
    if(root==NULL)
        return;
    arr[k++]=root->data;  
    convert(root->left,arr);
    convert(root->right,arr);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    int arr[1001];
    convert(root,arr);
    sort(arr,arr+k);
    int i=0;
    int j=k-1;
    while(i<j){
        if(arr[i]+arr[j]==sum){
            cout<< arr[i] <<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] > sum){
            j--;
        }
        else if(arr[i]+arr[j] < sum)
        i++;
    }
}