// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
    pair<int, int> find_max(vector<int> &arr, int i, int j) {
        int maxe = INT_MIN;
        int maxi;
        for (int k = i; k <= j; k++) {
            if (arr[k] > maxe) {
                maxe = arr[k];
                maxi = k;
            }
        }
        return {maxi, maxe};
    }
  
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        int i = 0, j = i + k - 1;
        int maxi = INT_MIN, maxe = INT_MIN;
        vector<int> ans;
        while (j < n) {
            if (maxi >= i) {
                if (arr[j] >= maxe) {
                    maxe = arr[j];
                    maxi = j;
                }
            }
            else {
                auto p = find_max(arr, i, j);
                maxi = p.first;
                maxe = p.second;
            }
            ans.push_back(maxe);
            i++;
            j++;
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
