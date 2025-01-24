class Solution:
  def findDifferentBinaryString(self, nums: list[str]) -> str:
    bitSize = len(nums[0])
    maxNum = 1 << bitSize
    numsSet = {int(num, 2) for num in nums}

    for num in range(maxNum):
      if num not in numsSet:
        return f'{num:0>{bitSize}b}'
