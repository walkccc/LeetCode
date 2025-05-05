from sortedcontainers import SortedList


class Solution:
  # Same as 3318. Find X-Sum of All K-Long Subarrays I
  def findXSum(self, nums: list[int], k: int, x: int) -> list[int]:
    ans = []
    windowSum = 0
    count = collections.Counter()
    top = SortedList()  # the top x elements
    bot = SortedList()  # the rest of the elements

    def update(num: int, freq: int) -> None:
      """Updates the count of num by freq and the window sum accordingly."""
      nonlocal windowSum
      if count[num] > 0:  # Clean up the old count.
        if [count[num], num] in bot:
          bot.remove([count[num], num])
        else:
          top.remove([count[num], num])
          windowSum -= num * count[num]
      count[num] += freq
      if count[num] > 0:
        bot.add([count[num], num])

    for i, num in enumerate(nums):
      update(num, 1)
      if i >= k:
        update(nums[i - k], -1)
      # Move the bottom elements to the top if needed.
      while bot and len(top) < x:
        countB, b = bot.pop()
        top.add([countB, b])
        windowSum += b * countB
      # Swap the bottom and top elements if needed.
      while bot and bot[-1] > top[0]:
        countB, b = bot.pop()
        countT, t = top.pop(0)
        bot.add([countT, t])
        top.add([countB, b])
        windowSum += b * countB
        windowSum -= t * countT
      if i >= k - 1:
        ans.append(windowSum)

    return ans
