class Solution:
  def minimumSeconds(self, nums: list[int]) -> int:
    n = len(nums)
    ans = n
    numToIndices = collections.defaultdict(list)

    for i, num in enumerate(nums):
      numToIndices[num].append(i)

    def getSeconds(i: int, j: int) -> int:
      """Returns the number of seconds required to make nums[i..j] the same."""
      return (i - j) // 2

    for indices in numToIndices.values():
      seconds = getSeconds(indices[0] + n, indices[-1])
      for i in range(1, len(indices)):
        seconds = max(seconds, getSeconds(indices[i], indices[i - 1]))
      ans = min(ans, seconds)

    return ans
