class Solution:
  def maxJumps(self, arr: list[int], d: int) -> int:
    n = len(arr)
    # dp[i] := the maximum jumps starting from arr[i]
    dp = [1] * n
    # a dcreasing stack that stores indices
    stack = []

    for i in range(n + 1):
      while stack and (i == n or arr[stack[-1]] < arr[i]):
        indices = [stack.pop()]
        while stack and arr[stack[-1]] == arr[indices[0]]:
          indices.append(stack.pop())
        for j in indices:
          if i < n and i - j <= d:
            # Can jump from i to j.
            dp[i] = max(dp[i], dp[j] + 1)
          if stack and j - stack[-1] <= d:
            # Can jump from stack[-1] to j
            dp[stack[-1]] = max(dp[stack[-1]], dp[j] + 1)
      stack.append(i)

    return max(dp)
