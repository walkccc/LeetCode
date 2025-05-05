class Solution:
  def captureForts(self, forts: list[int]) -> int:
    ans = 0

    j = 0
    for i, fort in enumerate(forts):
      if fort != 0:  # -1 or 1
        if fort == -forts[j]:
          ans = max(ans, i - j - 1)
        j = i

    return ans
