class Solution:
  def construct2DArray(self, original: list[int],
                       m: int, n: int) -> list[list[int]]:
    if len(original) != m * n:
      return []

    ans = [[0] * n for _ in range(m)]

    for i, num in enumerate(original):
      ans[i // n][i % n] = num

    return ans
