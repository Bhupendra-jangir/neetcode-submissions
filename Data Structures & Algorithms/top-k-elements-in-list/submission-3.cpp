class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int & it:nums){
            freq[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto & it:freq){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto [f,key] = pq.top();
            pq.pop();
            ans.push_back(key);
        }
        return ans;
    }
};