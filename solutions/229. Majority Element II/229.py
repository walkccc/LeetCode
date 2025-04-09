class Solution:
  def majorityElement(self, nums: list[int]) -> list[int]:
    ans1 = 0
    ans2 = 1
    count1 = 0
    count2 = 0

    for num in nums:
      if num == ans1:
        count1 += 1
      elif num == ans2:
        count2 += 1
      elif count1 == 0:
        ans1 = num
        count1 = 1
      elif count2 == 0:
        ans2 = num
        count2 = 1
      else:
        count1 -= 1
        count2 -= 1

    return [ans for ans in (ans1, ans2) if nums.count(ans) > len(nums) // 3]
