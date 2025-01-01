class Solution:
  def topKFrequent(self, nums: list[int], k: int) -> list[int]:
    ans = []
    bucket = [[] for _ in range(len(nums) + 1)]

    for num, freq in collections.Counter(nums).items():
      bucket[freq].append(num)

    for b in reversed(bucket):
      ans += b
      if len(ans) == k:
        return ans
