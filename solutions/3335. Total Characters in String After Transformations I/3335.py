class Solution:
  def lengthAfterTransformations(self, s: str, t: int) -> int:
    MOD = 1_000_000_007
    count = [0] * 26

    for c in s:
      count[ord(c) - ord('a')] += 1

    for _ in range(t):
      newCount = [0] * 26
      # 'a' -> 'b', 'b' -> 'c', ..., 'y' -> 'z'
      for i in range(25):
        newCount[i + 1] = count[i]
      # 'z' -> 'ab'
      newCount[0] = count[25]
      newCount[1] = (newCount[1] + count[25]) % MOD
      count = newCount

    return sum(count) % MOD
