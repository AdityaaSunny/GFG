//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &a, vector<int> &b,
                               vector<int> &c) {
        // Code Here
        vector<int>ans;
         set<int> st;
           int i ,j,k;
           i=j=k=0;
            while(i<a.size() && j<b.size() && k<c.size()){
                if(a[i]==b[j] && b[j]==c[k]){
                    st.insert(a[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(a[i]<b[j]){
                    i++;
                }
                else if(b[j]<c[k]){
                    j++;
                }else{
                    k++;
                }
                
            }
           for(auto i : st){
               ans.push_back(i);
           }
           return ans;
            
                                   
                               }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends