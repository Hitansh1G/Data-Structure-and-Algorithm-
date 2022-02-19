// Following is the Binary Tree node structure
/**************
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
***************/

bool isCousin(BinaryTreeNode<int> *root, int a, int b) {
    // Write your code here
	queue<pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*>> q;
    q.push({root, root});

    // a and b are the given two nodes
    // int a = arr[0], b = arr[1];

    while(!q.empty()) {
        int qsize = q.size();
        BinaryTreeNode<int> *parA = NULL, *parB = NULL;

        while(qsize--) {
            BinaryTreeNode<int>* ele = q.front().first;
            BinaryTreeNode<int>* par = q.front().second;
            q.pop();
            if(ele->data == a) {
                parA = par;
            }
            if(ele->data == b) {
                parB = par;
            }
            if(ele->left != NULL) {
                q.push({ele->left, ele});
            }
            if(ele->right != NULL) {
                q.push({ele->right, ele});
            }
            if(parA && parB) {
                break;
            }
        }
        if(parA && parB) {
            if(parA == parB) {
                return 0;
            }
            else {
                return 1;
            }
        }
        if(parA || parB) {
            return 0;
        }
    }
    return 0;
}

