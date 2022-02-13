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
int main(){
    Fast
    TreeNode<int>*root = New TreeNode<int>(1);
    TreeNode<int>*node1 = New TreeNode<int>(2);
    TreeNode<int>*node2 = New TreeNode<int>(3);

    //abhi tk hmne bs 3 node banaye ha connect nhi kia ha

    root->children.push_back(node1);
    root->children.push_back(node2);
    //ab mera connection bn gya ha .. and mera tree bn chuka ha
    return 0;
}