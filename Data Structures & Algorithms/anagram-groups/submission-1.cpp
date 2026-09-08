class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> temp = strs;
        vector<vector<int>> freq(n,vector<int>(26,0));

        for(int i=0;i<n;i++){
            for(char & ch:strs[i]){
                freq[i][ch-'a']++;
            }
        }
        map<vector<int>,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[freq[i]].push_back(i);
        }
        int size = mpp.size();
        int idx=0;
        vector<vector<string>> ans(size);
        for(auto & it:mpp){
            for(auto & a:it.second){
                ans[idx].push_back(temp[a]);
            }
            idx++;
        }
        return ans;
    }
};
