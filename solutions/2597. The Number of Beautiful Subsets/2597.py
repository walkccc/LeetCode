# e.g. nums = [2, 3, 4, 4], k = 2
#
# subset[0] = [2, 4, 4']
# subset[1] = [1]
# count = {2: 1, 4: 2, 1: 1}
#
# Initially, skip = len([]) = 0, pick = len([]) = 0
#
# * For values in subset[0]:
#   After 2:
#     skip = skip + pick = len([]) = 0
#     pick = (2^count[2] - 1) * (1 + skip + pick)
#          = len([[2]]) * len([[]])
#          = len([[2]]) = 1
#   After 4:
#     skip = skip + pick = len([[2]]) = 1
#     pick = (2^count[4] - 1) * (1 + skip)
#          = len([[4], [4'], [4, 4']]) * len([[]])
#          = len([[4], [4'], [4, 4']]) = 3
#
# * For values in subset[1]:
#   After 1:
#     skip = skip + pick
#          = len([[2], [4], [4'], [4, 4']]) = 4
#     pick = (2^count[1] - 1) * (1 + skip + pick)
#          = len([[1]]) * len([[], [2], [4], [4'], [4, 4']])
#          = len([[1], [1, 2], [1, 4], [1, 4'], [1, 4, 4']]) = 5
#
# So, ans = skip + pick = 9

class Solution:
  def beautifulSubsets(self, nums: List[int], k: int) -> int:
    count = collections.Counter(nums)
    modToSubset = collections.defaultdict(set)

    for num in nums:
      modToSubset[num % k].add(num)

    prevNum = -k
    skip = 0
    pick = 0

    for subset in modToSubset.values():
      for num in sorted(subset):
        nonEmptyCount = 2**count[num] - 1
        skip, pick = skip + pick, nonEmptyCount * \
            (1 + skip + (0 if num - prevNum == k else pick))
        prevNum = num

    return skip + pick
