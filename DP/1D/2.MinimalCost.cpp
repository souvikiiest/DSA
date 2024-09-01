// Recursion+memoization
    int helper(vector<int>& arr,int n, int& k, vector<int>& dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int p = INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i>=0){
                int l1 = abs(arr[n]-arr[n-i]) + helper(arr,n-i,k,dp);
                p = min(p,l1);
            }
        }
        return dp[n] = p;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        vector<int>dp(arr.size(),-1);
        return helper(arr, arr.size()-1,k,dp);
    }
// Tabulation
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=1; j<=k;j++){
                if(i-j>=0){
                    int l1 = abs(arr[i]-arr[i-j]) + dp[i-j];
                    dp[i] = min(l1,dp[i]);
                }
            }
        }
        return dp[n-1];
    }
