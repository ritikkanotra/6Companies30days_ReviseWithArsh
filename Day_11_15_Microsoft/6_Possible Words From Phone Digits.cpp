// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    vector<string> ans;
    unordered_map<int, vector<char> > um;
    
    void helper(int a[], int N, int cur, string str) {
        if (cur == N) {
            ans.push_back(str);
        }
        int num = a[cur];
        for (char ch: um[num]) {
            helper(a, N, cur + 1, str + ch);
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        // sort(a, a + N);
        
        um[2] = {'a', 'b', 'c'};
        um[3] = {'d', 'e', 'f'};
        um[4] = {'g', 'h', 'i'};
        um[5] = {'j', 'k', 'l'};
        um[6] = {'m', 'n', 'o'};
        um[7] = {'p', 'q', 'r', 's'};
        um[8] = {'t', 'u', 'v'};
        um[9] = {'w','x', 'y', 'z'};
        
        helper(a, N, 0, "");
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
