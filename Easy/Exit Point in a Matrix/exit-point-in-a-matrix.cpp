//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> FindExitPoint(int n, int m, vector<vector<int>> &mat)
    {
        // Code here
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, i = 0, j = 0;
        vector<int> ans;
        while (i < n and j < m and i >= 0 and j >= 0)
        {
            if (mat[i][j])
            {
                d = (d + 1) % 4;
                mat[i][j] = 0;
            }
            ans = {i, j};
            i += dir[d].first, j += dir[d].second;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends