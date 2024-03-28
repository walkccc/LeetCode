class Solution:
  def mctFromLeafValues(self, arr: List[int]) -> int:
    ans = 0
    stack = [math.inf]

    for a in arr:
      while stack and stack[-1] <= a:
        mid = stack.pop()
        # Multiply mid with next greater element in the array,
        # On the left (stack[-1]) or on the right (current number a)
        ans += min(stack[-1], a) * mid
      stack.append(a)

    return ans + sum(a * b for a, b in zip(stack[1:], stack[2:]))
