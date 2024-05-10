//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(vector<int> &answer , int n){
        answer.push_back(n);
        while(n != 1){
            if(n%2 == 0){
                n = static_cast<int>(sqrt(n));
            } else {
                n = static_cast<int>(pow(n,1.5));
            }
            answer.push_back(n);
        }
    }
    
    vector<int> jugglerSequence(int n) {
        vector<int> answer;
        solve(answer, n);
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends