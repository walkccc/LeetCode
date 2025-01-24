class Solution:
  def minOperations(self, nums: list[int], queries: list[int]) -> list[int]:
    n = len(nums)
    nums.sort()
    prefix = list(itertools.accumulate(nums, initial=0))
    splits = [(query, bisect.bisect_right(nums, query)) for query in queries]
    return [(query * i - prefix[i]) +
            (prefix[-1] - prefix[i] - query * (n - i))
            for query, i in splits]
