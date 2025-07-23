class Solution:
  def permute(self, n: int, k: int) -> list[int]:
    ans = []
    isLookingForEven = True
    remainingNumbers = list(range(1, n + 1))

    for turn in range(n):
      remainingPermutations = (math.factorial((n - 1 - turn) // 2) *
                               math.factorial((n - turn) // 2))
      found = False
      for index, number in enumerate(remainingNumbers):
        if number % 2 != isLookingForEven and (turn > 0 or n % 2 == 1):
          continue
        if k <= remainingPermutations:
          ans.append(remainingNumbers.pop(index))
          isLookingForEven = ans[-1] % 2 == 0
          found = True
          break
        k -= remainingPermutations
      if not found:
        return []

    return ans
