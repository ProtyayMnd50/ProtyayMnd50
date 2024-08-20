#define ll long long
class Solution {
public:
//cur--> in clipboard
//val->current value
    int func(int val,int clip,int n,vector<vector<int>>&dp){
        if(val>n)return 1e9;
        if(val==n)return 0;
        if(dp[val][clip]!=-1)return dp[val][clip];
        int copypaste=2+func(val+val,val,n,dp);
        int paste=1+func(val+clip,clip,n,dp);
        return dp[val][clip]=min(copypaste,paste);
    }
    int minSteps(int n) {
        // if(n==1)
        // return 0;
        // vector<vector<int>>dp(1010,vector<int>(1010,-1));
        // return 1+func(1,1,n,dp);

        //Top-down approach
        vector<int>dp(1001,0);
        dp[0]=0;
        dp[1]=0;
        // dp[2]=2;
        if(n>=2){
        for(int i=2;i<=n;i++){
            int fact=i/2;//trying to start from the largest divisor
            while(fact>=1){
                if(i%fact==0){//largest divisor
                    int fact_steps=dp[fact];
                    int copy=1;//one copy operation
                    int pasteOps=(i/fact-1);//itne paste operations
                    dp[i]=fact_steps+pasteOps+copy;
                    break;
                }
                fact--;
            }
        }
        }
        return dp[n];
    }
};