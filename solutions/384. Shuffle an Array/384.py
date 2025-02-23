class Solution:
  def __init__(self, nums: list[int]):
    self.nums = nums

  def reset(self) -> list[int]:
    return self.nums

  def shuffle(self) -> list[int]:
    arr = self.nums.copy()
    for i in range(len(arr) - 1, 0, -1):
      j = random.randint(0, i)
      arr[i], arr[j] = arr[j], arr[i]
    return arr
