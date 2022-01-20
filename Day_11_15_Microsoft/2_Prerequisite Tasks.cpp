// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    unordered_map<int, unordered_set<int> > um;

    bool solve(int val, unordered_set<int> &us, vector<bool> &isP) {
        if (isP[val]) {
            return true;
        }
        if (um.find(val) == um.end()) {
            return isP[val] = true;
        }
        if (us.find(val) != us.end()) {
            return isP[val] = false;
        }
        us.insert(val);
        bool b = true;
        for (int num: um[val]) {
            // us.insert(num);
            b = (b && solve(num, us, isP));
            if (b == false) {
                return isP[val] = false;
            }
            // us.erase(num);
        }
        us.erase(val);
        return isP[val] = b;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    for (auto p: prerequisites) {
	        um[p.first].insert(p.second);
	    }
	    vector<bool> isP(N, 0);
	    unordered_set<int> us;
	    for (int i = 0; i < N; i++) {
	        
	       // cout << solve(i, {}) << endl;
	       us.clear();
	       
	       if ((isP[i] = solve(i, us , isP)) == false) {
	           return false;
	       }
	        
	        
	       // unordered_set<int> us;
	       // int temp = p.first;
	       // while (um.find()) {
	            
	       //     if (us.find(temp) != us.end()) {
	       //         return false;
	       //     }
	       //     us.insert(temp);
	       //     temp = um[temp];
	       // }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
