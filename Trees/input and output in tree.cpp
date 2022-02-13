#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
#include "TreeNode.h"
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

TreeNode<int> *takeInput() {
//ye hme root retuern krega toh isliye iska dataype is TreeNode<int>
    int rootData;
    cout<<"Enter data"<<endl;
    cin >> rootData;
    TreeNode<int>*root = new TreeNode<int> (rootData);

    int n;
    cout<<"Enter no of children of "<<rootData<<endl;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        TreeNode<int>*child = takeInput();
        root->children.push_back(child);
    } 
    return root;

}


void printTree(TreeNode<int>*root){
    if(root ==NULL){
        return;
        //this is not a base case for recursion 
    }
    cout<<root->data<<" : ";
    for(int i=0 ; i<root->children.size() ; i++){
        cout<<root->children[i]->data << ", ";
    }
    cout<<endl;
    for(int i=0 ; i<root->children.size() ; i++){
        printTree(root->children[i]);
        //we dont need a base case coz agr koi aur children nhi hoga toh vo automatically return kr dega 0
    }
}

int main(){
    Fast
    // TreeNode<int>*root = new TreeNode<int>(1);
    // TreeNode<int>*node1 = new TreeNode<int>(2);
    // TreeNode<int>*node2 = new TreeNode<int>(3);

    // //abhi tk hmne bs 3 node banaye ha connect nhi kia ha

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int>*root = takeInput();
    //ab mera connection bn gya ha .. and mera tree bn chuka ha
    printTree(root);
    return 0;
}