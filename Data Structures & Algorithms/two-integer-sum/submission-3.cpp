class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> temp;
        int val = target/2;
        for(int i=0;i<n;i++){
            if(nums[i] == val) temp.push_back(i);
        }
        if(temp.size()==2) return temp;
        unordered_map<int,int> st;
        for(int i=0;i<n;i++){
            st[nums[i]] = i;
        }
        for(int i=0;i<n-1;i++){
            st.erase(nums[i]);
            int val = target-nums[i];
            if(st.find(val) != st.end()) return {i,st[val]};
        }
        return {};
    }
};
