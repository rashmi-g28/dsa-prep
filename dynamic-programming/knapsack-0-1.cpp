/*
link: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, also given an integer W representing the maximum capacity of the knapsack (the total weight it can hold).Put the items into the knapsack such that the sum of values associated with them is the maximum possible, without exceeding the capacity W.

Note: We can either include an item completely or exclude it entirely - we cannot include a fraction of an item.

Examples:

Input:  W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: There are two items with weight less than or equal to 4. If we select the item with weight 4, the possible value is 1, and if we select the item with weight 1, the possible value is 3. Hence, the maximum possible value is 3. We cannot put both items with weights 4 and 1 together because the capacity of the bag is 4.

Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
Output: 0 
Explanation: All the item weights are greater than the knapsack capacity.
*/

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int> (W+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<W;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int w=1;w<=W;w++){
                if((wt[i-1])<=w){
                    dp[i][w]=max(dp[i-1][w],(dp[i-1][w-wt[i-1]]+val[i-1]));
                }
                else{
                    dp[i][w]=dp[i-1][w];
                }
            }
        }
        return dp[n][W];
    }