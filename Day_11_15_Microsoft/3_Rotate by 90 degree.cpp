// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n = matrix.size();
    // vector<vector<int> > &a = matrix;
    vector<pair<int, int> > vec;
    // vec.push_back({0, 0});
    for (int z = 0; z < ceil((float)n / 2); z++) {
        vec.push_back({z, z});
        vec.push_back({n - 1 - z, z});
        vec.push_back({n - 1 - z, n - 1 - z});
        vec.push_back({z, n - 1 - z});
        
        
        // for (auto p: vec) {
        //     cout << p.first << " " << p.second << endl;
        // }
        // cout << endl;
        
        for (int i = z; i < n - 1 - z; i++) {
            int temp = matrix[vec[3].first][vec[3].second];
            for (int j = 3; j >= 1; j--) {
                matrix[vec[j].first][vec[j].second] = matrix[vec[j - 1].first][vec[j - 1].second];
            }
            matrix[vec[0].first][vec[0].second] = temp;
            
            vec[0].first++;
            vec[1].second++;
            vec[2].first--;
            vec[3].second--;
        }
        vec.clear();
    }
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends
