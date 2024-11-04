# 3163. String Compression III

__Type:__ Medium <br>
__Topics:__ String <br>
__Companies:__ Amazon, Qualcomm <br>
__Leetcode Link:__ [String Compression III](https://leetcode.com/problems/string-compression-iii)
<hr>

Given a string `word`, compress it using the following algorithm:

Begin with an empty string `comp`. While `word` is __not__ empty, use the following operation:
- Remove a maximum length prefix of `word` made of a single character `c` repeating __at most__ 9 times.
- Append the length of the prefix followed by `c` to `comp`.

Return the string `comp`.
<hr>

### Examples

- __Example 1:__ <br>
__Input:__ word = "abcde" <br>
__Output:__ "1a1b1c1d1e" <br>
__Explanation:__ <br>
Initially, `comp = ""`. Apply the operation 5 times, choosing `"a"`, `"b"`, `"c"`, `"d"`, and `"e"` as the prefix in each operation. <br>
For each prefix, append `"1"` followed by the character to `comp`.

- __Example 2:__ <br>
__Input:__ word = "aaaaaaaaaaaaaabb" <br>
__Output:__ "9a5a2b" <br>
__Explanation:__ <br>
Initially, `comp = ""`. Apply the operation 3 times, choosing `"aaaaaaaaa"`, `"aaaaa"`, and `"bb"` as the prefix in each operation. <br>
    - For prefix `"aaaaaaaaa"`, append `"9"` followed by `"a"` to `comp`.
    - For prefix `"aaaaa"`, append `"5"` followed by `"a"` to `comp`.
    - For prefix `"bb"`, append `"2"` followed by `"b"` to `comp`.
<hr>

### Constraints:
- <code>1 <= word.length <= 2 * 10<sup>5</sup></code>
- `word` consists only of lowercase English letters.
<hr>

### Hints:
- Each time, just cut the same character in prefix up to at max 9 times. It’s always better to cut a bigger prefix.