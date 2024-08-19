#define ll long long
class Solution {
public:
//cur--> in clipboard
//val->current value
    int func(int val,int clip,int n){
        if(val>n)return 1e9;
        if(val==n)return 0;

        int copypaste=2+func(val+val,val,n);
        int paste=1+func(val+clip,clip,n);
        return min(copypaste,paste);
    }
    int minSteps(int n) {
        if(n==1)
        return 0;

        return 1+func(1,1,n);
    }
};