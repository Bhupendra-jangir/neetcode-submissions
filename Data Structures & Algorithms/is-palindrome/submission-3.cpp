class Solution {
public: 
    
    bool isPalindrome(string a) {
        string s;
        for(char &ch:a){
            if(isalnum(ch)) s+=ch;
        }
        int i=0;
        int j=s.size()-1;
        if(j<1) return true;
        while(i<=j){
            while(!isalnum(s[i])) i++;
            while(!isalnum(s[j])) j--;
            if(tolower(s[i++])!=tolower(s[j--])) return false; 
        }
        return true;
    }
};
