class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        vector<int> sizes;
        for(auto & it:strs){
            int sz = it.size();
            sizes.push_back(sz);
        }

        for(int & it:sizes){
            encoded+=to_string(it);
            encoded+=',';
        }
        encoded+='#';
        for(auto & it:strs){
            encoded+=it;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<int> sizes;
        int i=0;
        int n = s.size();
        while(s[i] != '#'){
            int j=i;
            while(s[j] != ','){
                j++;
            }
            sizes.push_back(stoi(s.substr(i,j-i)));
            i = j+1;
        }
        i++;
        vector<string> ans;
        for(int & it:sizes){
            string temp = s.substr(i,it);
            ans.push_back(temp);
            i+=it;
        }
        return ans;
    }
};
