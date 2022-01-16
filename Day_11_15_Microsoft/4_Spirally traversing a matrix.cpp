// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    
    bool isValid(int i, int j, int r, int c) {
        if (i < 0 || i >= r || j < 0 || j >= c) {
            return false;
        }
        return true;
    }
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        char dirs[] = {'r', 'd', 'l', 'u'};
        char dir = 0;
        pair<int, int> p = {0, 0};
        vector<int> ans;
        set<pair<int, int> > us;
        int n = r * c;
        int i, j;
        // int temp = ;
        // ans.push_back(matrix[0][0]);
        // us.insert({0, 0});
        // n--;
        while (n--) {
            i = p.first;
            j = p.second;
            // if (!isValid(i, j) || (us.find({i, j}) != us.end())) {
            //     dir = (dir + 1) % 4;
            // }
            ans.push_back(matrix[i][j]);
            us.insert({i, j});
            switch (dirs[dir]) {
                case 'r': 
                    p.second++;
                    break;
                case 'd':
                    p.first++;
                    break;
                case 'l':
                    p.second--;
                    break;
                case 'u':
                    p.first--;
                    break;
            }
            // ans.push_back(matrix[p.first][p.second]);
            // us.insert({p.first, p.second});
            if (!isValid(p.first, p.second, r, c) || (us.find({p.first, p.second}) != us.end())) {
                p.first = i;
                p.second = j;
                dir = (dir + 1) % 4;
                switch (dirs[dir]) {
                    case 'r': 
                        p.second++;
                        break;
                    case 'd':
                        p.first++;
                        break;
                    case 'l':
                        p.second--;
                        break;
                    case 'u':
                        p.first--;
                        break;
                }
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
