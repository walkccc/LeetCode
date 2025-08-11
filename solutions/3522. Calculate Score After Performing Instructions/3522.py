class Solution:
  def calculateScore(self, instructions: list[str], values: list[int]) -> int:
    n = len(instructions)
    ans = 0
    i = 0
    seen = set()

    while 0 <= i < n and i not in seen:
      seen.add(i)
      if instructions[i] == 'add':
        ans += values[i]
        i += 1
      elif instructions[i] == 'jump':
        i += values[i]

    return ans
