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
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, vector<int>& v) {
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr){
        if(root->data==k){
            //ostream_iterator<int> out(cout, " ");
            //copy(v.begin(), v.end(), out);
            copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
            // for(int i=0; i<v.size(); i++)
            //  cout << v[i] << ' ';
            cout << k << endl;
        }
        return;
    }
    v.push_back(root->data);
    rootToLeafPathsSumToK(root->left, k-root->data, v);
    rootToLeafPathsSumToK(root->right, k-root->data, v);
    v.pop_back();
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<BinaryTreeNode<int> *> s, path;
    do {
        while(root!=nullptr) {
            s.push_back(root);
            path.push_back(root);
            root = root->left;
        }
        if(!s.empty()){
            root = s.back();
            s.pop_back();
            if(root->right==nullptr){
                int sum = 0;
                for(int i=0; i<path.size(); i++)
                    sum += path[i]->data;
                if(sum==k){
                    for(int i=0; i<path.size(); i++)
                        cout << path[i]->data << ' ';
                    cout << endl;
                }
                if(!s.empty()){
                    while(path.back()!=s.back())
                        path.pop_back();
                }
            }
            root = root->right;
        }
    } while(!s.empty() || root!=nullptr);
}