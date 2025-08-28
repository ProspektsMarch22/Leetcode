# 459. Repeated Substring Pattern

### Programming Skills Study Plan

# Intuition

This looked like a simple problem. It was marked as "Easy", but i found it quite challenging. 

My first thought was to check for a pattern that had distinct letters. So, the get_sub function was born to give me the first substring of distinct letters in the string.

But then i had this test case:

"abaababaab"

If i checked for "ab", it would be no good. But if i checked for "abaab", that's a string formed by 2 equal substrings. 

# Problem Solved

If checking for a distinct letter pattern was a good start, i had to check for sets of this distinct letter pattern + 1, if possible, as long as the set doesn't become greater than the max number of substrings per string, which is 2. So, the length of the substring checked must not be greater than the length of the original string.

Since i'm reviewing strings that must be formed by substrings repeated multiple times, if the length of the substring is not a divisor of the length of the original string, than the original string cannot be recreated combining the current substring being checked. 

So there comes the recursivity: i check a case; it doesn't apply, i check the case plus the next letter. Until either i go through the length limit or find a valid substring.
