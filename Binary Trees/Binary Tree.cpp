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
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
using namespace std;
int main(){
    Fast
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>*node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>*node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    return 0;
}