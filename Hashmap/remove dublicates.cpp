vector<int> removeduplicates(int arr[] , int size){
    vector<int>ouput;
    unordered_map<int,bool> seen;
    for(int i=0 ; i<size ; i++){
        if(seen.count(a[i]) > 0 ){
            continue;
        }
        seen[a[i]] = true;
        ouput.push_back(a[i]); 
    }
    return ouput;
}