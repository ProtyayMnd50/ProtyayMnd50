class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       int mx=arrays[0].back();
       int mn=arrays[0].front();
       //abhi tak ka minimum and maximum
       int result=0;
       for(int i=1;i<arrays.size();i++){
        int cmn=arrays[i].front();
        int cmx=arrays[i].back();
        result=max(result,abs(cmx-mn));
        result=max(result,abs(mx-cmn));
        mx=max(mx,cmx);
        mn=min(mn,cmn);
       }
       cout<<result<<endl;
       return result; 
    }
};