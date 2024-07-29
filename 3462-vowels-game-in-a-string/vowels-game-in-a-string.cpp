class Solution {
public:
    bool doesAliceWin(string s) {
        string comp="aeiou";
        int vw=0;
        for(int i=0;i<s.size();i++){
            int pos=comp.find(s[i]);
            if(pos>=0&&pos<5)vw++;
        }
        if(vw==0)return false;
        else
        return true;
    }
};