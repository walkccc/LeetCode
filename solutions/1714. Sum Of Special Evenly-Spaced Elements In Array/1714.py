class Solution:
  def solve(self, nums: list[int], queries: list[list[int]]) -> list[int]:
    kMod = 10**9 + 7
    n = len(nums)
    sqrtN = int(n**0.5)
    # prefix[x][y] = sum(nums[x + ay]), where a >= 0 and x + ay < n
    # Set prefix[i][j] to nums[i] to indicate the sequence starts with nums[i].
    prefix = [[num] * sqrtN for num in nums]

    for x in range(n - 1, -1, -1):
      for y in range(1, sqrtN):
        if x + y < n:
          prefix[x][y] += prefix[x + y][y]
          prefix[x][y] %= kMod

    return [prefix[x][y] if y < sqrtN
            else sum(nums[x::y]) % kMod
            for x, y in queries]
