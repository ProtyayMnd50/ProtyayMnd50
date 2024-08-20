class Solution {
public:
    
  
    int dp[2][101][101]; 
    int solveForAlice(vector<int>& piles, bool person, int i, int M) {
        int n=piles.size();
        if(i >= n)
            return 0;
        
        if(dp[person][i][M] != -1)
            return dp[person][i][M];
        
        int result = (person == true) ? -1 : INT_MAX;
        
        int stones = 0;
        
        for(int x = 1; x <= min(2*M, n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(person ==true) { //Alice's turn
                result = max(result, stones + solveForAlice(piles, false, i+x, max(M, x)));
            } else { //Bob's turn
                result = min(result, solveForAlice(piles, true, i+x, max(M, x)));
            }
            
        }
        
        return dp[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        // n = piles.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solveForAlice(piles, 1, 0, 1);
    }
};