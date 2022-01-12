// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] %= k;
        }
        int arr[k] = {0};
        for (int num: nums) {
            if (num == 0) {
                if (arr[0] > 0) {
                arr[0]--;
                }
                else {
                    arr[0]++;
                }
            }
            else {
                if (arr[k - num] > 0) {
                    arr[k - num]--;
                }
                else {
                    arr[num]++;
                }
            }
            // for (int num: arr) {
            //     cout << num << " ";
            // }
            // cout << endl;
        }
        for (int num: arr) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
