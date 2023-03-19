class Solution:
  def wonderfulSubstrings(self, word: str) -> int:
    ans = 0
    prefix = 0  # Binary prefix
    count = [0] * 1024  # Binary prefix count
    count[0] = 1  # Empty string ""

    for c in word:
      prefix ^= 1 << ord(c) - ord('a')
      ans += count[prefix]  # All chars occur even times
      # `c` occurs odd times
      ans += sum(count[prefix ^ 1 << i] for i in range(10))
      count[prefix] += 1

    return ans
