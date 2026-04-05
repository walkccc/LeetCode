class Solution:
  def longestValidSubstring(self, word: str, forbidden: list[str]) -> int:
    forbiddenSet = set(forbidden)
    ans = 0
    r = len(word) - 1  # rightmost index of the valid substring

    for l in range(len(word) - 1, -1, -1):
      for end in range(l, min(l + 10, r + 1)):
        if word[l:end + 1] in forbiddenSet:
          r = end - 1
          break
      ans = max(ans, r - l + 1)

    return ans
