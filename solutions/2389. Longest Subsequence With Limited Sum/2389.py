class Solution:
  def answerQueries(self, nums: list[int], queries: list[int]) -> list[int]:
    nums.sort()

    def numOfElementsLessThan(query: int) -> int:
      summ = 0
      for i, num in enumerate(nums):
        summ += num
        if summ > query:
          return i
      return len(nums)

    return [numOfElementsLessThan(query) for query in queries]
