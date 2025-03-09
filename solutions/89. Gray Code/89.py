class Solution:
  def grayCode(self, n: int) -> list[int]:
    ans = [0]

    for i in range(n):
      for j in reversed(range(len(ans))):
        ans.append(ans[j] | 1 << i)

    return ans
