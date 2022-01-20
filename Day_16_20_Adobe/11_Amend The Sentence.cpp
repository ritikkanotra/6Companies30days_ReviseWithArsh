// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans = "";
        int i = 0;
        for (char ch: s) {
            if (isupper(ch)) {
                if (i != 0) {
                    ans += ' ';
                }
                ch = tolower(ch);
            }
            ans += ch;
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
