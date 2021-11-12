int height(TreeNode<int>*root){
    int max = 0 ;
    vector<int>v;
    if(root->children.size()==0){
        return 1;
    }
    for(int i= 0 ; i < root->children.size();i++){
        v.push_back(height(root->children[i]));
    }
    
    for(int i= 0 ; i < root->children.size();i++){
        if(v[i]>max){
            max = v[i];
        }
    }
    return max+1;
    
}