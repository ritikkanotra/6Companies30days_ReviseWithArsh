// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int m, n;
    
    bool solve(vector<vector<char>>& board, int i, int j, string word, int cur, string str) {
        
        // cout << "YES" << endl;
        
        if (cur == word.size()) {
            return str == word;
        }
        
        if (board[i][j] != word[cur]) {
            return false;
        }
        
        str += word[cur];
        // cout << str << endl;
        char temp = board[i][j];
        board[i][j] = '#';
        
        if (i + 1 < m) {
            if (solve(board, i + 1, j, word, cur + 1, str)) {
                return true;
            }
        }
        
        if (i - 1 >= 0) {
            if (solve(board, i - 1, j, word, cur + 1, str)) {
                return true;
            }
        }
        
        if (j + 1 < n) {
            if (solve(board, i, j + 1, word, cur + 1, str)) {
                return true;
            }
        }
        
        if (j - 1 >= 0) {
            if (solve(board, i, j - 1, word, cur + 1, str)) {
                return true;
            }
        }
        
        board[i][j] = temp;
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, i, j, word, 0, "")) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
