/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL) return;
    int result = root->data; // root node
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        printPostOrder(root->children[i]);
    cout << root->data << ' ';
}