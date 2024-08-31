class Solution {
public:
typedef pair<double,int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];//weight or dist in case of standard djistra's
            adj[u].push_back({v,wt});
             adj[v].push_back({u,wt});
        }
        vector<double>dist(n,-1);
        priority_queue<pair<double,int>>pq;
        dist[start_node]=1;
        pq.push({1,start_node});
        while(!pq.empty()){
            pair<double,int>pr=pq.top();
            pq.pop();
            double cW=pr.first;
            int cN=pr.second;
            for(auto &x:adj[cN]){
                int nN=x.first;
                double nW=x.second;
                double tot=nW*cW;
                 if(tot>dist[nN]){
                    dist[nN]=tot;
                    pq.push({tot,nN});
                }
            }
        }
        for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
        }

        return dist[end_node]==-1?0:dist[end_node];

    }
};