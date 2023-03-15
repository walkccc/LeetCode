class Solution:
  def findLonely(self, nums: List[int]) -> List[int]:
    count = collections.Counter(nums)
    return [num for num, freq in count.items()
            if freq == 1 and
            count[num - 1] == 0 and
            count[num + 1] == 0]
