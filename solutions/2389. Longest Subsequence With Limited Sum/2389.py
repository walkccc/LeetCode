class Solution:
  def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
    nums.sort()

    def numOfElementsLessThan(query: int) -> int:
      summ = 0
      for i, num in enumerate(nums):
        summ += num
        if summ > query:
          return i
      return len(nums)

    return [numOfElementsLessThan(query) for query in queries]
