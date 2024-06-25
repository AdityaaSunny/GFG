//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int FindCoverage(vector<vector<int>>&matrix){
        // Code here
        int n=matrix.size(),m=matrix[0].size(),sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    if(i-1 >= 0) sum += matrix[i-1][j]; 
                    if(i+1 <= n-1)sum+= matrix[i+1][j];
                    if(j-1 >= 0) sum += matrix[i][j-1];
                    if(j+1 <= m-1)sum += matrix[i][j+1];
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		Solution obj;
		int ans = obj.FindCoverage(matrix);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends