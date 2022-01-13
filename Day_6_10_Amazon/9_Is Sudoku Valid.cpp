// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSquareValid(vector<vector<int>> &arr, int row, int col) {
        unordered_set<int> s;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (arr[i][j] != 0) {
                    if (s.find(arr[i][j]) != s.end()) {
                        return false;
                    }
                    s.insert(arr[i][j]);
                }
            }
        }
        return true;
    }

    int isValid(vector<vector<int>> &arr){
        // code here
        for (int i = 0; i < 9; i++) {
            unordered_set<int> s;
            for (int j = 0; j < 9; j++) {
                if (arr[i][j] != 0) {
                    if (s.find(arr[i][j]) != s.end()) {
                        return 0;
                    }
                    s.insert(arr[i][j]);
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            unordered_set<int> s;
            for (int i = 0; i < 9; i++) {
                if (arr[i][j] != 0) {
                    if (s.find(arr[i][j]) != s.end()) {
                        return 0;
                    }
                    s.insert(arr[i][j]);
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isSquareValid(arr, i, j)) {
                    return 0;
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
