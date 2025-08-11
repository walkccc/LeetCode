class Solution:
  def findSubstringInWraproundString(self, s: str) -> int:
    maxLength = 1
    # count[i] := the number of substrings ending in ('a' + i)
    count = [0] * 26

    for i in range(len(s)):
      if i > 0 and (ord(s[i]) - ord(s[i - 1]) == 1
                    or ord(s[i - 1]) - ord(s[i]) == 25):
        maxLength += 1
      else:
        maxLength = 1
      index = ord(s[i]) - ord('a')
      count[index] = max(count[index], maxLength)

    return sum(count)
