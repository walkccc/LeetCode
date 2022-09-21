class Solution:
  def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    ans = []
    bucket = [[] for _ in range(len(nums) + 1)]

    for num, freq in Counter(nums).items():
      bucket[freq].append(num)

    for b in reversed(bucket):
      ans += b
      if len(ans) == k:
        return ans
