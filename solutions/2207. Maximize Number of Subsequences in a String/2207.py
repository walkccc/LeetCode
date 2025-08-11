class Solution:
  def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
    ans = 0
    count0 = 0  # the count of the letter pattern[0]
    count1 = 0  # the count of the letter pattern[1]

    for c in text:
      if c == pattern[1]:
        ans += count0
        count1 += 1
      if c == pattern[0]:
        count0 += 1

    # It is optimal to add pattern[0] at the beginning or add pattern[1] at the
    # end of the text.
    return ans + max(count0, count1)
