class Solution:
  def waysToReachStair(self, k: int) -> int:
    # Let's say we have `down` operation 1 and `jump` operation 2.
    # The final stair is 1 + (2^0 + 2^1 + ... + 2^(jump - 1)) - down = k.
    # => 1 + (2^jump - 1) - down = k.
    # => down = 2^jump - k.
    # Since `down` operations cannot be used consecutively, there're jump + 1
    # positions (before and after each `jump`) for  `down`. The maximum jump is
    # 29, as it satisfies the condition down = 2^jump - k <= jump + 1, with k
    # being the maximum value of 10^9.
    kMaxJump = 29
    ans = 0

    for jump in range(kMaxJump + 1):
      down = (1 << jump) - k
      if down < 0 or down > jump + 1:
        continue
      ans += math.comb(jump + 1, down)

    return ans
