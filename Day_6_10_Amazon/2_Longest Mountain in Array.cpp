class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int low = i - 1, high = i + 1;
                while (low >= 0 && arr[low] < arr[low + 1]) {
                    low--;
                }
                while (high < n && arr[high] < arr[high - 1]) {
                    high++;
                }
                ans = max(ans, high - low - 1);
            }
        }
        return ans;
    }
};
