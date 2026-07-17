/*
link: https://leetcode.com/problems/valid-anagram/description/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

bool isAnagram(string s, string t) {
        unordered_map<char,int> occurance;
        unordered_map<char,int> count;
        if(s.length()!=t.length()){
            return false;
        }
        for(char x : s){
            occurance[x]++;
        }
        for(char x : t){
            count[x]++;
        }
        for(char x : t){
            if(occurance[x]==0 || occurance[x]!=count[x]){
                return false;
            }
        }
        return true;
    }