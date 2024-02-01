class Solution:
  def minFlips(self, s: str) -> int:
    n = len(s)
    # count[0][0] :=  the number of '0' in the even indices
    # count[0][1] :=  the number of '0' in the odd indices
    # count[1][0] :=  the number of '1' in the even indices
    # count[1][1] :=  the number of '1' in the odd indices
    count = [[0] * 2 for _ in range(2)]

    for i, c in enumerate(s):
      count[ord(c) - ord('0')][i % 2] += 1

    # min(make all 0s in the even indices + make all 1s in the odd indices,
    #     make all 1s in the even indices + make all 0s in the odd indices)
    ans = min(count[1][0] + count[0][1], count[0][0] + count[1][1])

    for i, c in enumerate(s):
      count[ord(c) - ord('0')][i % 2] -= 1
      count[ord(c) - ord('0')][(n + i) % 2] += 1
      ans = min(ans, count[1][0] + count[0][1], count[0][0] + count[1][1])

    return ans
