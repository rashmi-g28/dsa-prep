/*
link: https://leetcode.com/problems/palindrome-number/description/

Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
*/
    bool isPalindrome(int x) {
        string str1=to_string(x);
        string rev=str1;
        reverse(rev.begin(),rev.end());
        if(str1==rev){
            return true;
        }
        return false;
    }

    //optimized solution
    bool isPalindrome(int x) {
        int dup = x, rev=0;
        if(x < 0 || ( x % 10 == 0 && x != 0)){
            return false;
            }while ( x > 0){
             int ld = x % 10;
             if( rev > INT_MAX / 10 ){
                return false;
             }
             rev = (rev * 10) + ld;
             x = x/10;
        }
        return rev == dup;    
    }