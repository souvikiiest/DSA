You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Recursion + memoizaion
int helper(vector<int>& nums, int n,vector<int>& dp){
       if(n<0) return 0;
       if(n==0) return nums[0];
       if(dp[n]!=-1) return dp[n];
       //either i can rob the house or skip the house
       int rob = nums[n] + helper(nums,n-2,dp);
       int skip = helper(nums, n-1, dp);
       return dp[n]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return 0;
        vector<int> dp(n,-1);
        return helper(nums,n-1,dp);
    }

// Tabulation
int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums[0];
        vector<int> dp(n,-1);
        dp[0]=nums[0]; dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            //int rob = INT_MIN;
            int rob = nums[i] + dp[i-2];
            int skip = dp[i-1];
            dp[i]=max(rob,skip);
        }
        return dp[n-1];
    }

//Space optimization
int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums[0];
        //vector<int> dp(n,-1);
        int prev2=nums[0], prev=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int cur = INT_MIN;
            int rob = nums[i] + prev2;
            int skip = prev;
            cur=max(rob,skip);
            prev2=prev;
            prev=cur;
            
        }
        return prev;
    }
