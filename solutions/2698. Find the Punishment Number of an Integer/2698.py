class Solution:
  def punishmentNumber(self, n: int) -> int:
    def isPossible(accumulate: int, running: int, numChars: List[str], s: int, target: int) -> bool:
      """
      Returns True if the sum of any split of `numChars` equals to the target.
      """
      if s == len(numChars):
        return target == accumulate + running
      d = int(numChars[s])
      return (
          # Keep growing the `running`.
          isPossible(accumulate, running * 10 + d, numChars, s + 1, target) or
          # Start a new `running`.
          isPossible(accumulate + running, d, numChars, s + 1, target)
      )

    return sum(i * i
               for i in range(1, n + 1)
               if isPossible(0, 0, str(i * i), 0, i))
