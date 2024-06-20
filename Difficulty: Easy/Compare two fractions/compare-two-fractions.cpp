//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        size_t c=str.find(", ");
        string a=str.substr(0,c);
        string b=str.substr(c+2);
        size_t s1=a.find('/');
        size_t s2=b.find('/');
        int n1=stoi(a.substr(0,s1));
        int d1=stoi(a.substr(s1+1));
        int n2=stoi(b.substr(0,s2));
        int d2=stoi(b.substr(s2+1));
        double value1 = static_cast<double>(n1) / d1;
        double value2 = static_cast<double>(n2) / d2;
        if(value1>value2) return a;
        else if(value1<value2) return b;
        else return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends