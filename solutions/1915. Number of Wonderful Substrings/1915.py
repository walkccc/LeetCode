class Solution:
  def wonderfulSubstrings(self, word: str) -> int:
    ans = 0
    prefix = 0  # the binary prefix
    count = [0] * 1024  # the binary prefix count
    count[0] = 1  # the empty string ""

    for c in word:
      prefix ^= 1 << ord(c) - ord('a')
      # All the letters occur even number of times.
      ans += count[prefix]
      # `c` occurs odd number of times.
      ans += sum(count[prefix ^ 1 << i] for i in range(10))
      count[prefix] += 1

    return ans
