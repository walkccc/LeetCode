class Solution:
  def getSmallestString(self, n: int, k: int) -> str:
    ans = []

    for i in range(n):
      remainingLetters = n - i - 1
      rank = max(1, k - remainingLetters * 26)
      ans.append(chr(ord('a') + rank - 1))
      k -= rank

    return ''.join(ans)
