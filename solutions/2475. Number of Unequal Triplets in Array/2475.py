# Assume that we have 4 kinds of numbers a, b, c, and d in the count map.
#
# What we want is:
#   cnt[a] * cnt[b] * cnt[c]
#   cnt[a] * cnt[b] * cnt[d]
#   cnt[a] * cnt[c] * cnt[d]
#   cnt[b] * cnt[c] * cnt[d]
#
# The above combinations can be reduced as:
#
# prev                       | curr   | next
#
# (0)                        * cnt[a] * (cnt[b] + cnt[c] + cnt[d])
# (cnt[a])                   * cnt[b] * (cnt[c] + cnt[d])
# (cnt[a] + cnt[b])          * cnt[c] * (cnt[d])
# (cnt[a] + cnt[b] + cnt[c]) * cnt[d] * (0)

class Solution:
  def unequalTriplets(self, nums: list[int]) -> int:
    ans = 0
    prev = 0
    next = len(nums)

    for freq in collections.Counter(nums).values():
      next -= freq
      ans += prev * freq * next
      prev += freq

    return ans
