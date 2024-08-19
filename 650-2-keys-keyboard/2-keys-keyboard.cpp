#define ll long long
class Solution {
public:
//cur--> in clipboard
    ll func(ll n,ll val,ll cur){
        if(val>n)
        return 1e9;
        if(n==val)
        return 0;
        ll st1=2+func(n,val+val,val);
        ll st2=1+func(n,val+cur,cur);
        return min(st1,st2);
    }
    int minSteps(int n) {
        if(n==1)
        return 0;
        return 1+func(n,1,1);
    }
};