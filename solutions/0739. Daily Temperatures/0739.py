class Solution:
  def dailyTemperatures(self, T: List[int]) -> List[int]:
    ans = [0] * len(T)
    stack = []

    for i, t in enumerate(T):
      while stack != [] and t > T[stack[-1]]:
        index = stack.pop()
        ans[index] = i - index
      stack.append(i)

    return ans
