class Solution:
  def minimumPartition(self, s: str, k: int) -> int:
    ans = 1
    curr = 0

    for c in s:
      curr = curr * 10 + int(c)
      if curr > k:
        curr = int(c)
        ans += 1
      if curr > k:
        return -1

    return ans
