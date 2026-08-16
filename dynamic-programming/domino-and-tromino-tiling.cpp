/*
link: https://leetcode.com/problems/domino-and-tromino-tiling/

You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are shown above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000
*/

    int numTilings(int n) {
        vector<int> full(n+1),partial(n+1);
        int MOD=1000000007;
        full[0]=1;
        full[1]=1;
        partial[0]=0;
        partial[1]=0;

        for(int i=2;i<=n;i++){
            full[i]=(1LL*full[i-1]+1LL*full[i-2]+(2LL*partial[i-1]))%MOD;
            partial[i]=(1LL*partial[i-1]+1LL*full[i-2])%MOD;
        }

        return full[n]%MOD;
    }