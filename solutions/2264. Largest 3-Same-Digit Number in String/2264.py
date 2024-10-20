class Solution:
  def largestGoodInteger(self, num: str) -> str:
    return max(num[i - 2:i + 1]
               if num[i] == num[i - 1] == num[i - 2]
               else '' for i in range(2, len(num)))
