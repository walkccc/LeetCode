class Solution:
  def minKBitFlips(self, A: List[int], K: int) -> int:
    ans = 0
    flippedTime = 0

    for r, a in enumerate(A):
      if r >= K and A[r - K] == 2:
        flippedTime -= 1
      if flippedTime % 2 == a:
        if r + K > len(A):
          return -1
        ans += 1
        flippedTime += 1
        A[r] = 2

    return ans
