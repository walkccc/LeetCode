class Solution:
  def lastVisitedIntegers(self, words: list[str]) -> list[int]:
    ans = []
    nums = []
    k = 0

    for word in words:
      if word == 'prev':
        k += 1
        ans.append(-1 if k > len(nums) else nums[-k])
      else:
        k = 0
        nums.append(int(word))

    return ans
