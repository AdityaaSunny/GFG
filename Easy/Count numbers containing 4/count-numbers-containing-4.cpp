//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int ans = 0;
        int count = 0;
        int digit = 1;
        while (digit <= n)
        {
            int mod = n % (digit * 10) / digit;
            if (mod < 4)
            {
                ans += count * mod;
            }
            else if (mod == 4)
            {
                ans = count * mod + (n % digit) + 1;
            }
            else {
                ans += count * (mod - 1) + digit;
            }
            count = count * 9 + digit;
            digit *= 10;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends