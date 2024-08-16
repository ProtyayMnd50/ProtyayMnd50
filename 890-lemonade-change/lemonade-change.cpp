class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                mp[5]++;
            }else if(bills[i]==10){
                if(mp[5]<1)return false;
                mp[10]++;
                mp[5]--;
                if(mp[5]==0)mp.erase(5);
            }else if(bills[i]==20){
                if(mp[10]>=1&&mp[5]>=1){
                    mp[10]--;if(mp[10]==0)mp.erase(10);
                    mp[5]--;if(mp[5]==0)mp.erase(5);
                }else if(mp[5]>=3){
                    mp[5]-=3;if(mp[5]==0)mp.erase(5);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};