class Solution:
  def sumSubarrayMins(self, A: List[int]) -> int:
    n = len(A)
    kMod = int(1e9 + 7)

    ans = 0
    prev = [-1] * n
    next = [n] * n
    stack1 = []
    stack2 = []

    for i, a in enumerate(A):
      while stack1 and A[stack1[-1]] > a:
        stack1.pop()
      prev[i] = stack1[-1] if stack1 else -1
      stack1.append(i)

      while stack2 and A[stack2[-1]] > a:
        index = stack2.pop()
        next[index] = i
      stack2.append(i)

    for i, a in enumerate(A):
      ans = (ans + a * (i - prev[i]) * (next[i] - i)) % kMod

    return ans
