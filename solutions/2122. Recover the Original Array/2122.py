class Solution:
  def recoverArray(self, nums: list[int]) -> list[int]:
    nums = sorted(nums)

    def getArray(x: int, count: collections.Counter) -> list[int]:
      arr = []
      for num in nums:
        if count[num] == 0:
          continue
        if count[num + x] == 0:
          return []
        count[num] -= 1
        count[num + x] -= 1
        arr.append(num + x // 2)
      return arr

    count = collections.Counter(nums)

    for i in range(1, len(nums)):
      x = nums[i] - nums[0]  # 2 * k
      if x <= 0 or x % 2 == 1:
        continue
      arr = getArray(x, count.copy())
      if arr:
        return arr
