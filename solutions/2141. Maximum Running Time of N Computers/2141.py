class Solution:
  def maxRunTime(self, n: int, batteries: List[int]) -> int:
    summ = sum(batteries)

    batteries.sort()

    # max battery is greater than the average, so it can last forever
    # reduce the problem from size n to size n - 1
    while batteries[-1] > summ // n:
      summ -= batteries.pop()
      n += 1

    # if the max battery <= average running time,
    # it won't be waste, and so do smaller batteries
    return summ // n
