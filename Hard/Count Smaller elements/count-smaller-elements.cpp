//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int> v, ans;
        ans.push_back(0);
        v.push_back(arr[n-1]);
        for(int i=n-2; i>=0; --i){
            auto ind = lower_bound(v.begin(), v.end(),arr[i]);      
            if(ind != v.end()){
                int dis = distance(v.begin(), ind);
                v.insert(v.begin()+dis,arr[i]); 
                ans.push_back(dis);           
            }else{
                ans.push_back(v.size());
                v.push_back(arr[i]);
            }  
            
        }  
        reverse(ans.begin(), ans.end());
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends