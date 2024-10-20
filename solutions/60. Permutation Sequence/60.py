class Solution:
  def getPermutation(self, n: int, k: int) -> str:
    ans = ''
    nums = [i + 1 for i in range(n)]
    fact = [1] * (n + 1)  # fact[i] := i!

    for i in range(2, n + 1):
      fact[i] = fact[i - 1] * i

    k -= 1  # 0-indexed

    for i in reversed(range(n)):
      j = k // fact[i]
      k %= fact[i]
      ans += str(nums[j])
      nums.pop(j)

    return ans
