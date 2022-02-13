TreeNode<int>* takeInputLevelwise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin >>rootData;
    TreeNode<int>*root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no of children of " <<front->data<<endl;
        int numchild;
        cin >> numchild;
        for(int i=0 ; i<numchild ; i++){
            cout<<"Enter "<<i << "child of " << front->data<<endl;
            int childData;
            cin >> childData;
            TreeNode<int>*child new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}