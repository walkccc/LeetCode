class Solution:
  def lastSubstring(self, s: str) -> str:
    i = 0
    j = 1
    k = 0  # Number of same characters of s[i:] and s[j:]

    while j + k < len(s):
      if s[i + k] == s[j + k]:
        k += 1
      elif s[i + k] > s[j + k]:
        # Now s[i:i + k] == s[j:j + k] and s[i + k] > s[j + k] means that
        # We should start from s[j + k] to find a possible larger substring
        j += k + 1
        k = 0
      else:
        # Now s[i:i + k] == s[j:j + k] and s[i + k] < s[j + k] means that
        # Either starting from s[i + k + 1] or s[j] has a larger substring
        i = max(i + k + 1, j)
        j = i + 1
        k = 0

    return s[i:]
