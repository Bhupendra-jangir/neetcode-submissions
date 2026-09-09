class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i=0;i<n;i++){
            int k = target-numbers[i];
            int j=-1;
            int low=i+1,high = n-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(numbers[mid] == k){
                    j=mid;
                    break;
                }
                else if(numbers[mid] > k) high = mid-1;
                else low = mid+1;
            }
            if(j!=-1) return {i+1,j+1};
        }
        return {};
    }
};
