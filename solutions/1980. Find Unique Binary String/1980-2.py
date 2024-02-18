class Solution:
  def findDifferentBinaryString(self, nums: List[str]) -> str:
    return ''.join('1' if num[i] == '0' else '0' for i, num in enumerate(nums))
