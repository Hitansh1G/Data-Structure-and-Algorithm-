#include<bits/stdc++.h>
string uniqueChar(string str) {
	// Write your code here
   	vector<int> table(256, 0);
    vector<char> chars;
    for(auto i : str)
        chars.push_back(i);
    int endIndex = 0; 
    for(int i = 0; i < chars.size(); i++){
        if (table[chars[i]] == 0){
            table[chars[i]] = -1;
            chars[endIndex++] = chars[i];
        }
    }
    string ans = "";
    for(int i = 0; i < endIndex; i++)
        ans += chars[i];
    return ans;
}

