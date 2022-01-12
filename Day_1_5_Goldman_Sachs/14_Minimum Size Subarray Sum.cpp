class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (high < nums.size()) {
            sum += nums[high++];
            if (sum >= target) {
                ans = min(ans, high - low);
            }
            int temp = 0;
            while (sum >= target) {
                sum -= nums[low++];
                temp = 1;
            }
            if (temp) {
                ans = min(ans, high - low + 1);
            }
            
        }
        if (sum == target) {
            ans = min(ans, high - low);
        }
        return (ans == INT_MAX ? 0 : ans);
        
        
    }
};
