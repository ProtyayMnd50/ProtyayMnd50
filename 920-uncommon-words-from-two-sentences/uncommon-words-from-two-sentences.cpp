class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp1;
        map<string,int>mp2;
        set<string>s;
        s1=s1+" ";
        s2=s2+" ";
        string x1="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=' ')
                x1+=s1[i];
            else{
                s.insert(x1);
                mp1[x1]++; x1="";
            }
        }
         string x2="";
          for(int i=0;i<s2.size();i++){
            if(s2[i]!=' ')
                x2+=s2[i];
            else{
                s.insert(x2);
                mp2[x2]++;
                x2="";
            }
        }
        vector<string>ans;
        for(auto &x:s){
            cout<<x<<" "<<mp1[x]<<" "<<mp2[x]<<endl;
            if(mp1[x]==0&&mp2[x]==1)ans.push_back(x);
            else if(mp1[x]==1&&mp2[x]==0)ans.push_back(x);
        }
        return ans;
    }
};