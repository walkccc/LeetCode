class Solution:
  def countTheNumOfKFreeSubsets(self, nums: list[int], k: int) -> int:
    modToSubset = collections.defaultdict(set)

    for num in nums:
      modToSubset[num % k].add(num)

    prevNum = -k
    skip = 0
    pick = 0

    for subset in modToSubset.values():
      for num in sorted(subset):
        skip, pick = (skip + pick,
                      1 + skip + (0 if num - prevNum == k else pick))
        prevNum = num

    return 1 + skip + pick
