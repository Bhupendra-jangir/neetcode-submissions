class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;

        for(auto &it : nums){
            freq[it]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(freq[a]!=freq[b]) return freq[a] > freq[b];
            return a<b;
        });

        vector<int> ans;
        for(int i=0;i<n && ans.size()<k ;i++){
            if(i==0 || nums[i]!=ans.back()){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};