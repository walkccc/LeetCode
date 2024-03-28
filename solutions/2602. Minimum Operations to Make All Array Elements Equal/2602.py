class Solution:
  def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
    n = len(nums)
    nums.sort()
    prefix = [0] + list(itertools.accumulate(nums))
    splits = [(query, bisect.bisect_right(nums, query)) for query in queries]
    return [(query * i - prefix[i]) +
            (prefix[-1] - prefix[i] - query * (n - i))
            for query, i in splits]
