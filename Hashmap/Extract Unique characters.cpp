#include<unordered_map>
string uniqueChar(string s) {
	// Write your code here
    unordered_map<char,int> exists; 
  int index = 0;  
  for(int i=0;s[i]!='\0';i++)
  { 
    if(exists[s[i]]==0) 
    { 
      s[index++] = s[i]; 
      exists[s[i]]++; 
    } 
  } 
    s[index]='\0';
  return s; 
}

