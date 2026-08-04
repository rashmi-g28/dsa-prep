/*
link: https://leetcode.com/problems/partition-equal-subset-sum/

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

    bool canPartition(vector<int>& nums) {
        int n=nums.size(),tsum=0;
        
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        if(tsum%2!=0){
            return false;
        }
        vector<vector<int>> total(n+1,vector<int>((tsum/2)+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(tsum/2);j++){
                if(nums[i-1]>j){
                    total[i][j]=total[i-1][j];
                }
                else{
                    total[i][j]=max(total[i-1][j],total[i-1][j-nums[i-1]]+nums[i-1]);
                }
            }
        }
        if(total[n][tsum/2]==tsum/2){
            return true;
        }
        return false;
    }