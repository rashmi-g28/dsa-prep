/*
link: https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int result=0,prefixSum=0;
        unordered_map<int,int> prefixCounts;
        prefixCounts[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int s=prefixSum-k;
            if(prefixCounts.count(s)){
                result+=prefixCounts[s];
            }
            prefixCounts[prefixSum]+=1;
        }
        return result;
    }



/*

Structure of the Hash Map 
(std::unordered_map)To look backward in O(1) constant time, use a Hash Map as a tally notebook.Key (int): A unique running total (PrefixSum) seen in the past.Value (int): The frequency (how many times) that specific total has occurred.Why frequency matters: If a past total of 5 appeared 3 times, it means there are 3 distinct starting points behind you that can form a valid subarray ending exactly where you are standing right now.

The Two Mandatory Golden Rules
1. The "Base Case" Zero InitializationBefore processing any elements, you must seed your map with a running total of 0 that has been seen exactly 1 time.

prefixCounts[0] = 1;
Why? If a valid subarray starts from the very first element (index 0), its PrefixSum will equal k. The backward math becomes k - k = 0. If you don't seed [0] = 1, your map won't find the 0, and you will miss subarrays that start at index 0.

2. Update the Map on EVERY StepLogging your current total into the map must happen outside of any conditional blocks at the end of the loop iteration.

prefixCounts[prefixSum] += 1; // Runs every single loop pass
Why? Even if you find a match on the current step, you still need to record your current PrefixSum. It acts as the stepping stone for future matches further down the array.💻 Standard Code Template (C++)cppint subarraySum(vector<int>& nums, int k) {

Complexity Analysis
Time Complexity: O(N) — You traverse the array exactly once. Hash map lookups and insertions take O(1) average time.
Space Complexity: O(N) — In the worst-case scenario (e.g., all positive numbers), the map will store up to N unique prefix sum keys.

*/