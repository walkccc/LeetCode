class Solution:
  def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
    ans = 0
    count0 = 0
    count1 = 0

    for i, c in enumerate(text):
      if c == pattern[1]:
        ans += count0
        count1 += 1
      if c == pattern[0]:
        count0 += 1

    # adding pattern[0] in the beginning or
    # adding pattern[1] in the end is optimal
    return ans + max(count0, count1)
