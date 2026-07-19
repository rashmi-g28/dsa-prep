/*
link: https://leetcode.com/problems/first-unique-character-in-a-string/description/

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

int firstUniqChar(string s) {
        int n=s.length();
        int result=-1;
        int i=0,j=1;
        if(n==1){
            return 0;
        }
        while(j<n && i<n){
            if(s[i]==s[j] && i!=j){
                i++;
                j=0;
                result=-1;
            }
            else{
                result=i;
                j++;
            }
        }
        return result;
    }

//optimal approach
int getUniqueChar(string &s){
        
        vector<int> freq(26,0);

        for(auto ch:s){
            freq[ch-'a']++;
        }

        int n = s.size();
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
    int firstUniqChar(string s) {
        return getUniqueChar(s);
    }