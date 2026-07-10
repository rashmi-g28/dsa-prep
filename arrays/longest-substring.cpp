/*
link:https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int result=0;
        int cnt=1,i=0,j=1;
        vector<char> found;
        found.push_back(s[0]);

        if(s==" " || len==1){
            result=1;
        }
        while(j<len){ 
            if(find(begin(found),end(found),s[j]) != end(found)){
                i++;
                j=i+1;
                found.clear();
                found.push_back(s[i]);
                cnt=1;
            }
            else{
                found.push_back(s[j]);
                cnt++;
                j++;
            }
            result=max(result,cnt);
        }
        return result;
    }

    // optimal approach
    int lengthOfLongestSubstring(string s) {
        int last[256];

        for (int i = 0; i < 256; i++)
            last[i] = -1;

        int l = 0, ans = 0;

        for(int r = 0; r < s.length();r++){
            if(last[s[r]] >= l)
                l = last[s[r]] + 1;
            
            last[s[r]] = r;

            ans = max(r-l+1 , ans);
        }

        return ans;
    }