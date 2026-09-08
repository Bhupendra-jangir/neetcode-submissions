class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int & it:nums) st.insert(it);
        int ans=0;
        for(int & it:nums){
            int temp=0;
            if(st.find(it-1) == st.end()){
                int curr=it;
                while(st.find(curr) != st.end()){
                    temp++;
                    curr++;
                }
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};
