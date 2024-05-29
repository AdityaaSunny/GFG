//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
    string S=s1;
    string T=s2;
    int n=S.size();
      int m=T.size();
        int mod=1e9+7;
      vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      for(int i=0;i<=n;i++){
          dp[i][0]=1;
      }
      
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
               
                int match=0;
                int dont=0;
                if(S[i-1]==T[j-1]){
                    match=dp[i-1][j-1];
                }
                {
                    dont=dp[i-1][j];
                }
                
                dp[i][j]= (match%mod+dont%mod)%mod;
          }
      }
      return dp[n][m];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends