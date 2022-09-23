class Solution:
  def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
    nums.sort()
    
    def numOfElementsLessThan(q: int) -> int:
      summ = 0
      for i, num in enumerate(nums):
        summ += nums[i]
        if summ > q:
          return i
      return len(nums)

    return [numOfElementsLessThan(q) for q in queries]
  
  