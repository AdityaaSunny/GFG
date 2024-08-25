//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  int solve(int index, vector<int>& height, int n, vector<int>& dp) {
        
        if (index >= n - 1) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int oneStep = INT_MAX;
        int twoStep = INT_MAX;
        if ( (index + 1) <= n - 1 )
             oneStep = abs(height[index] - height[index + 1]) + solve(index + 1, height, n, dp);
        if ((index + 2) <= n - 1)
            twoStep = abs(height[index] - height[index + 2]) + solve(index + 2, height, n, dp);
        
        return dp[index] = min(oneStep, twoStep);
        
    }
    public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int index = 0;
        vector<int> dp(n + 1, -1);
        return solve(index, height, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends