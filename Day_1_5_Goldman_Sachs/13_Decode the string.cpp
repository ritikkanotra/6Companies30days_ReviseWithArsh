// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    string repeatString(string str, int n) {
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += str;
        }
        return ans;
    }

    string decodedString(string s){
        // code here
        stack<int> st1;
        stack<string> st2;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch >= '0' &&  ch <= '9') {
                string temp = "";
                while (s[i] >= '0' &&  s[i] <= '9') {
                    temp += s[i];
                    i++;
                }
                i--;
                st1.push(stoi(temp));
            }
            else if (ch == ']') {
                string temp = "";
                while (st2.top() != "[") {
                    temp = st2.top() + temp;
                    st2.pop();
                }
                st2.pop();
                st2.push(repeatString(temp, st1.top()));
                // st2.push(temp);
                st1.pop();
                // cout << st2.top() << endl;
            }
            else {
                string temp = "";
                temp += ch;
                st2.push(temp);
                // cout << (ch) << endl;
            }
            // if (!st2.empty()) 
            //     cout << st2.top() << endl;
        }
        // cout << st2.size() << endl;
        return st2.top();
        
    }
        
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
