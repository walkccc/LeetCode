class Solution:
  def shortestSequence(self, rolls: list[int], k: int) -> int:
    ans = 1  # the the next target length
    seen = set()

    for roll in rolls:
      seen.add(roll)
      if len(seen) == k:
        # Have all combinations that form `ans` length, and we are going to
        # extend the sequence to `ans + 1` length.
        ans += 1
        seen.clear()

    return ans
