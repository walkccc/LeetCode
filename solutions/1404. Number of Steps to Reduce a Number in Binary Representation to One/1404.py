class Solution:
  def numSteps(self, s: str) -> int:
    ans = 0
    chars = [c for c in s]

    # All the trailing 0s can be popped by 1 step.
    while chars[-1] == '0':
      chars.pop()
      ans += 1

    if ''.join(chars) == '1':
      return ans

    # The `s` is now odd, so add 1 to the `s` and cost 1 step.
    # All the 1s will become 0s and can be popped by 1 step.
    # All the 0s will become 1s and can be popped by 2 steps (adding 1 then
    # dividing by 2).
    return ans + 1 + sum(1 if c == '1' else 2 for c in chars)
