class Solution:
  def numTimesAllBlue(self, flips: list[int]) -> int:
    ans = 0
    rightmost = 0

    for i, flip in enumerate(flips):
      rightmost = max(rightmost, flip)
      # max(flips[0..i]) = rightmost = i + 1,
      # so flips[0..i] is a permutation of 1, 2, ..., i + 1.
      if rightmost == i + 1:
        ans += 1

    return ans
