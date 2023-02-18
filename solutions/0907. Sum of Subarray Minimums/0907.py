class Solution:
  def sumSubarrayMins(self, arr: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(arr)
    ans = 0
    # prev[i] := index k s.t. arr[k] is the prev min in arr[:i]
    prev = [-1] * n
    # next[i] := index k s.t. arr[k] is the next min in arr[i + 1:]
    next = [n] * n
    stack = []

    for i, a in enumerate(arr):
      while stack and arr[stack[-1]] > a:
        index = stack.pop()
        next[index] = i
      if stack:
        prev[i] = stack[-1]
      stack.append(i)

    for i, a in enumerate(arr):
      ans += a * (i - prev[i]) * (next[i] - i)
      ans %= kMod

    return ans
