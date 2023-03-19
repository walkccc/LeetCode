class Solution:
  def numSteps(self, s: str) -> int:
    ans = 0
    chars = [c for c in s]

    # All trailing 0s can be popped by 1 step.
    while chars[-1] == '0':
      chars.pop()
      ans += 1

    if ''.join(chars) == '1':
      return ans

    # s is now odd, so add 1 to s and cost 1 step.
    # All 1s will become 0s and be popped by 1 step.
    # All 0s will become 1s and be popped by 2 step (add 1 then divide by 2).
    return ans + 1 + sum(1 if c == '1' else 2 for c in chars)
