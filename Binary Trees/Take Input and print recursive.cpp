void printTree(BinaryTreeNode <int>*root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeinput(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin >> rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>rootData;
    BinaryTreeNode<int>*leftchild = takeinput();
    BinaryTreeNode<int>*rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}