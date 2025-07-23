from enum import Enum


class State(Enum):
  FIRST = 0  # first element - add to sum and start product
  SUBTRACT = 1  # second element - subtract from sum and multiply product
  ADD = 2  # third element - add to sum and multiply product


class Solution:
  def maxProduct(self, nums: list[int], k: int, limit: int) -> int:
    MIN = -5000
    if abs(k) > sum(nums):
      return -1

    @functools.lru_cache(None)
    def dp(i: int, product: int, state: State, k: int) -> int:
      if i == len(nums):
        return (product if k == 0 and state != State.FIRST and product <= limit
                else MIN)
      res = dp(i + 1, product, state, k)
      if state == State.FIRST:
        res = max(res, dp(i + 1, nums[i], State.SUBTRACT, k - nums[i]))
      if state == State.SUBTRACT:
        res = max(res, dp(i + 1, min(product * nums[i], limit + 1),
                          State.ADD, k + nums[i]))
      if state == State.ADD:
        res = max(res, dp(i + 1, min(product * nums[i], limit + 1),
                          State.SUBTRACT, k - nums[i]))
      return res

    ans = dp(0, 1, State.FIRST, k)
    return -1 if ans == MIN else ans
