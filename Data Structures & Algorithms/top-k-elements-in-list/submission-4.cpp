class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        int maxi = 0;
        for(int & it:nums){
            freq[it]++;
            maxi= max(maxi,freq[it]);
        }
        vector<vector<int>> a(maxi+1);
        for(auto & it:freq){
            a[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=maxi;i>=0;i--){
            if(ans.size()>=k) return ans;
            for(auto & it:a[i]) ans.push_back(it);
        }
        return ans;
    }
};