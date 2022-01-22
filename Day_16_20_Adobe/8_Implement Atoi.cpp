// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0;
        int cnt = 0;
        int flag = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] < '0' || str[i] > '9') {
                if (i == 0 && str[i] == '-') {
                    flag = 1;
                    break;
                }
                return -1;
            }
            int temp = str[i] - '0';
            ans += (temp * pow(10, cnt));
            cnt++;
        }
        if (flag == 1) {
            ans *= -1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
