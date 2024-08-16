class Solution {
public:
    int func(int i,int j,vector<pair<int,int>>&vp){
        if(vp[i].second!=vp[j].second)
        return abs(vp[i].first-vp[j].first);
        
        
        return max(func(i+1,j,vp),func(i,j-1,vp));
    }
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        vector<pair<int,int>>vp;//element,index
        for(int i=0;i<n;i++){
            int N=arrays[i].size();
            vp.push_back({arrays[i][0],i});
            vp.push_back({arrays[i][N-1],i});
        }
        sort(vp.begin(),vp.end());
        cout<<"vp"<<endl;
        for(auto &x:vp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        int nu=vp.size();
        return func(0,nu-1,vp);
    }
};