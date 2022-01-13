// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    string ans = "";
		    int count[26] = {0};
		    queue<char> q;
		    for (int i = 0; i < s.length(); i++) {
		        count[s[i] - 'a']++;
		        q.push(s[i]);
		        while (!q.empty() && count[q.front() - 'a'] > 1) {
		            q.pop();
		        }
		        if (q.empty()) {
		            ans += '#';
		        }
		        else {
		            ans += q.front();
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
