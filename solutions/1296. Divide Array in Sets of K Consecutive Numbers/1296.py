class Solution:
  def isPossibleDivide(self, nums: List[int], k: int) -> bool:
    count = Counter(nums)

    for start in sorted(count):
      value = count[start]
      if value > 0:
        for i in range(start, start + k):
          count[i] -= value
          if count[i] < 0:
            return False

    return True
