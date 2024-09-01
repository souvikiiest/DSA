/*Geek wants to climb from the 0th stair to the (n-1)th stair. 
At a time the Geek can climb either one or two steps. 
A height[N] array is also given. Whenever the geek jumps 
from stair i to stair j, the energy consumed in the jump 
is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.
*/

// Memoization with recursion
    int f(vector<int>& height,vector<int>& dp, int n){
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int n1 = abs(height[n]-height[n-1]) + f(height,dp,n-1);
        int n2=INT_MAX;
        if(n>1)
             n2=abs(height[n]-height[n-2]) + f(height,dp,n-2);
        return dp[n] = min(n1,n2);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        return f(height,dp,n-1);
    }

//Tabulation
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int l1 = dp[i-1] + abs(height[i]-height[i-1]);
            int l2=INT_MAX;
            if(i>1) l2 = dp[i-2] + abs(height[i]-height[i-2]);
            dp[i] = min(l1,l2);
        }
        return dp[n-1];
    }

//Space optimization
    int minimumEnergy(vector<int>& height, int n) {
       int prev=0;
        int prev2=0;
        int curi;
        int l2=INT_MAX;
        
        for(int i=1;i<n;i++){
            int l1 = prev + abs(height[i]-height[i-1]);
            if(i>1) l2 = prev2 + abs(height[i]-height[i-2]);
            curi = min(l1,l2);
            prev2 = prev;
            prev = curi;
        }
        return prev;
        
    }

