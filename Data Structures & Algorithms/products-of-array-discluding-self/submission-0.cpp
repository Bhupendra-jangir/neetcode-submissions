class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> pre(n,1),suf(n,1);
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]*nums[i-1];
            suf[n-i-1] = suf[n-i]*nums[n-i];
        }
        vector<int> ans(n,0);
        ans[0] = suf[0];
        ans[n-1] = pre[n-1];
        for(int i=0;i<n-1;i++){
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};
