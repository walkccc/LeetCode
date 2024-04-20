class Solution:
  def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
    ans = [0] * len(temperatures)
    stack = []  # a decreasing stack

    for i, temperature in enumerate(temperatures):
      while stack and temperature > temperatures[stack[-1]]:
        index = stack.pop()
        ans[index] = i - index
      stack.append(i)

    return ans
