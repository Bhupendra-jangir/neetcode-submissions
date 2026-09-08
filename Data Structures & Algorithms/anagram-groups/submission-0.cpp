class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> temp = strs;
        for(int i=0;i<n;i++){
            sort(strs[i].begin(),strs[i].end());
        }
        map<string,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[strs[i]].push_back(i);
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
