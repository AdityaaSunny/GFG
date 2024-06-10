//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
         unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        vector<char> v;
        v.push_back('!');
        v.push_back('#');
        v.push_back('$');
        v.push_back('%');
        v.push_back('&');
        v.push_back('*');
        v.push_back('?');
        v.push_back('@');
        v.push_back('^');
        
        for(int i = 0; i < n; ++i) mp1[nuts[i]]++;
        for(int i = 0; i < n; ++i) mp2[bolts[i]]++;
        
        int j = 0, k = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(mp1.find(v[i]) != mp1.end()) {
                int cnt = mp1[v[i]];
                while(cnt--) nuts[j++] = v[i];
            }
            if(mp2.find(v[i]) != mp2.end()) {
                int cnt = mp2[v[i]];
                while(cnt--) bolts[k++] = v[i];
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends