class Solution {
public:
    void callDFS(int node,vector<int>&visited,vector<vector<int>>&stones){
        visited[node]=true;
        int cr=stones[node][0];
        int cc=stones[node][1];
        for(int i=0;i<stones.size();i++){
            if(visited[i]==false){
                int nr=stones[i][0];
                int nc=stones[i][1];
                if(nr==cr||nc==cc){
                    callDFS(i,visited,stones);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>visited(n,false);
        int groups=0;
        for(int i=0;i<stones.size();i++){
            if(visited[i]==false){
            groups++;
            callDFS(i,visited,stones);
            }
        }
       int ans=n-groups;//total number of stones- number of groups
        return ans;
    }
};