// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    
    
    // static bool fn(char c1, char c2) {
    //     if (priority[c1] > priority[c2]) {
    //         return true;
    //     }
    //     return false;
    // }
    
    void sortval(char arr[], int n, unordered_map<char, int> &priority) {
        
        auto fn = [&](char c1, char c2) {
            return (priority[c1] > priority[c2]);
        };
        
        sort(arr, arr + n, fn);
    }
    
    
    

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    
	    unordered_map<char, int> priority;
	    
	    priority['!'] = 9;
	    priority['#'] = 8;
	    priority['$'] = 7;
	    priority['%'] = 6;
	    priority['&'] = 5;
	    priority['*'] = 4;
	    priority['@'] = 3;
	    priority['^'] = 2;
	    priority['~'] = 1;
	    
	   // auto fn = [](char c1, char c2) {
	   //     return (Solution::priority[c1] > Solution::priority[c2]);
	   // };
	    
	   // sort(nuts, nuts + n, fn);
	   // sort(bolts, nuts + n, fn);
	   
	   sortval(nuts, n, priority);
	   sortval(bolts, n, priority);
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
