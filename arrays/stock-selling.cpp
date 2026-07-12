/*
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

int maxProfit(vector<int>& prices) {
        int result=0;
        int curProfit=0;
        int n=prices.size();
        int i=0,j=1;
    
        while(j<n){
            if(prices[i]<prices[j]){
                curProfit=prices[j]-prices[i];
                result=max(result,curProfit);
                j++;
            }
            else{
                i++;
                j=i+1;
            }
        }
        return result;
    }

//Optimal approach
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int l = 0;
        int r = 0;
        int diff = 0;

        if (prices.size() == 0) {
            return max;
        }

        l = 0;
        r = 1;
        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;
            } else {
                diff = prices[r] - prices[l];
                if (diff > max) {
                    max = diff;
                }
            }
            r++;
        }

        return max;
    }