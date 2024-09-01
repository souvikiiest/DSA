//Question: You are given an Undirected Graph having unit weight 
//of the edges, find the shortest path from src to all the vertex 
//and if it is unreachable to reach any vertex, then return -1 for 
//that vertex.





vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> dis(N,INT_MAX);
        vector<vector<int>>adj(N);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src]=0;
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto& nums:adj[node]){
                if(dis[nums]>N){
                q.push({nums,dist+1});
                dis[nums]=dist+1;
            }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dis[i]==INT_MAX)
                dis[i]=-1;
        }
        return dis;
        
    }
