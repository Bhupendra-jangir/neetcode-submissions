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

        int idx = 0;
        int i = 0;

        while(i < n){

            if(idx == k)
                return ans;

            ans.push_back(nums[i]);
            idx++;

            while(i + 1 < n && nums[i + 1] == nums[i])
                i++;

            i++;  // move to next different number
        }

        return ans;
    }
};