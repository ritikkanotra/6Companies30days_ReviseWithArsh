// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
    string ans;
    int cnt = 1;
    int i;
    for (i = 1; i < src.length(); i++) {
        if (src[i] == src[i - 1]) {
            cnt++;
        }
        else {
            ans += src[i - 1] + to_string(cnt);
            cnt = 1;
        }
    }
    ans += src[i - 1] + to_string(cnt);
    return ans;
    
}     
 
