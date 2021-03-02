class Solution:
  def maxWidthRamp(self, A: List[int]) -> int:
    ans = 0
    stack = []

    for i, a in enumerate(A):
      if stack == [] or a <= A[stack[-1]]:
        stack.append(i)

    for i in range(len(A))[::-1]:
      while stack and A[i] >= A[stack[-1]]:
        ans = max(ans, i - stack.pop())

    return ans
