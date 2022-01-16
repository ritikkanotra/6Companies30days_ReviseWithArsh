// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int rows, cols;
    unordered_map<int, int> um;
    
    bool isValid(int i, int j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols) {
            return false;
        }
        return true;
    }
    
    void helper(vector<vector<int>>& grid, int i, int j, int grp) {
        if (!isValid(i, j) || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = grp;
        um[grp]++;
        helper(grid, i - 1, j, grp);
        helper(grid, i + 1, j, grp);
        helper(grid, i, j - 1, grp);
        helper(grid, i, j + 1, grp);
        helper(grid, i - 1, j - 1, grp);
        helper(grid, i + 1, j + 1, grp);
        helper(grid, i - 1, j + 1, grp);
        helper(grid, i + 1, j - 1, grp);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        rows = grid.size();
        cols = grid[0].size();
        int grp = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    helper(grid, i, j, ++grp);
                }
            }
        }
        int ans = 0;
        for (auto p: um) {
            ans = max(ans, p.second);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
