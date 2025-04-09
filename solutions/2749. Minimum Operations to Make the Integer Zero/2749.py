class Solution:
  def makeTheIntegerZero(self, num1: int, num2: int) -> int:
    # If k operations are used, num1 - [(num2 + 2^{i_1}) + (num2 + 2^{i_2}) +
    # ... + (num2 + 2^{i_k})] = 0. So, num1 - k * num2 = (2^{i_1} + 2^{i_2} +
    # ... + 2^{i_k}), where i_1, i_2, ..., i_k are in the range [0, 60].
    # Note that for any number x, we can use "x's bit count" operations to make
    # x equal to 0. Additionally, we can also use x operations to deduct x by
    # 2^0 (x times), which also results in 0.

    for ops in range(61):
      target = num1 - ops * num2
      if target.bit_count() <= ops <= target:
        return ops

    return -1
