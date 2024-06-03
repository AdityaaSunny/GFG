//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int>mp;
        int temp=0;
        int ans=0;
        for(int i=0;i<N;i++){
            temp+=A[i];
            if(mp.find(temp-K)!=mp.end()){
                ans=max(ans,i-mp[temp-K]);
                // cout<<mp[temp-K]<<" "<<i<<endl;
            }
            if(mp.find(temp)==mp.end()){
                mp[temp]=i;
            }
            if(temp==K)ans=max(ans,i+1);
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends