// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    pair<int, int> find_max(int *arr, int i, int j) {
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
  
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
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
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
