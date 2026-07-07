/*
link: https://leetcode.com/problems/rotate-array/description/

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

void rotate(vector<int>& nums, int k) {
        int n=nums.size();

        if(n==k){
            return;
        }
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }

    /*
    what new I learnt:
    Modulo Optimization (k % n): Huge rotation counts are redundant. Reducing k using the remainder operator changes a problem from a potential crash or timeout into a quick, safe calculation.Time Complexity Matters: Shifting elements one by one creates an \(O(n \times k)\) bottleneck (TLE). Processing elements in place using clever patterns drops this to an optimal O(n) runtime.The Reversal Algorithm: You can achieve complex array shifts without allocating extra memory (O(1) space) simply by reversing the entire array and then reversing specific sub-sections.Iterator Syntax: You learned how to manipulate specific zones of a container using std::reverse with half-open iterator boundaries like nums.begin() + k.
    */