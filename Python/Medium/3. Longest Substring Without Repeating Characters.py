# Given a string s, find the length of the longest substring without repeating characters.

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1
        if len(s) == 2:
            if s[0] == s[1]:
                return 1
            else:
                return 2
        longest = 0
        for i in range(len(s)):
            sub = s[i]
            for j in range(i+1, len(s)):
                if s[j] in sub:
                    break
                sub += s[j]
            if len(sub) > longest:
                longest = len(sub)
        return longest