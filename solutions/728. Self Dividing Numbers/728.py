class Solution:
  def selfDividingNumbers(self, left: int, right: int) -> list[int]:
    return [num for num in range(left, right + 1) if all(n != 0 and num % n == 0 for n in map(int, str(num)))]
