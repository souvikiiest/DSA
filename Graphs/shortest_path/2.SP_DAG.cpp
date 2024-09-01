///{ Driver Code Starts
// Initial Template for C++
//Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

//Find the shortest path from src(0) vertex to all the vertices 
//and if it is impossible to reach any vertex, then return -1 
//for that vertex.





#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution { 
  public:
    void dfs(int src,stack<int> &st, vector<int>& vis,vector<vector<pair<int,int>>> &adj ){
        vis[src] = true;
        for(auto& it:adj[src]){
            int first = it.first;
            if(!vis[first]){
                dfs(first,st,vis,adj);
            }
        }
        st.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<M;i++){
            
                int u=edges[i][0];
                int v=edges[i][1];
                int d=edges[i][2];
                adj[u].push_back({v,d});
            
        }
        stack<int>st;
        vector<int>vis(N,false);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        vector<int>dist(N,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(dist[top]!=INT_MAX){
            for(auto& it:adj[top]){
                int node = it.first;
                int dis = it.second;
                int ndist = dis+dist[top];
                if(dist[node]>ndist){
                    dist[node]=ndist;
                }
            }
            
        }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends/{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution { 
  public:
    void dfs(int src,stack<int> &st, vector<int>& vis,vector<vector<pair<int,int>>> &adj ){
        vis[src] = true;
        for(auto& it:adj[src]){
            int first = it.first;
            if(!vis[first]){
                dfs(first,st,vis,adj);
            }
        }
        st.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<M;i++){
            
                int u=edges[i][0];
                int v=edges[i][1];
                int d=edges[i][2];
                adj[u].push_back({v,d});
            
        }
        stack<int>st;
        vector<int>vis(N,false);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        vector<int>dist(N,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(dist[top]!=INT_MAX){
            for(auto& it:adj[top]){
                int node = it.first;
                int dis = it.second;
                int ndist = dis+dist[top];
                if(dist[node]>ndist){
                    dist[node]=ndist;
                }
            }
            
        }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
