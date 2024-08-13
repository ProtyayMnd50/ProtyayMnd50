class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=INT_MIN;
        for(auto &x:edges){
            n=max({n,x[0],x[1]});
        }
        vector<int>adj[n+1];
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==(n-1)){
                ans=i;break;
            }
        }
        return ans;
    }
};