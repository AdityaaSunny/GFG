//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    unordered_map<int,vector<int>>adj;
    void dfs(vector<int>&vis,int i,vector<int>&inorder,int &sum,int &ele){
        vis[i]=1;
        ele++;
        sum=sum+inorder[i];
        for(auto it:adj[i]){
            if(vis[it]==0){
                dfs(vis,it,inorder,sum,ele);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int>inorder(v+1,0);
        
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            inorder[edges[i][0]]++;
            inorder[edges[i][1]]++;
        }
        int start=1;
        vector<int>vis(v+1,0);
        int ct=0;
        for(int i=1;i<v+1;i++){
            if(vis[i]==0){
                int sum=0;
                int ele=0;
                dfs(vis,i,inorder,sum,ele);
                sum=sum/2;
                int u=ele*(ele-1);
                u=u/2;
                if(sum==u){
                    ct++;
                }
            }
        }
        return ct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends