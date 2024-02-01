class Solution:
  def minSwaps(self, grid: List[List[int]]) -> int:
    n = len(grid)
    ans = 0
    # suffixZeros[i] := the number of suffix zeros in the i-th row
    suffixZeros = [n if 1 not in row else row[::-1].index(1) for row in grid]

    for i in range(n):
      neededZeros = n - i - 1
      # Get the first row with suffix zeros >= `neededZeros` in suffixZeros[i:..n).
      j = next((j for j in range(i, n) if suffixZeros[j] >= neededZeros), -1)
      if j == -1:
        return -1
      # Move the rows[j] to the rows[i].
      for k in range(j, i, -1):
        suffixZeros[k] = suffixZeros[k - 1]
      ans += j - i

    return ans
