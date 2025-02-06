class Solution:
  def maxEnergyBoost(
      self,
      energyDrinkA: list[int],
      energyDrinkB: list[int]
  ) -> int:
    dpA = 0  # the maximum energy boost if the last drink is A
    dpB = 0  # the maximum energy boost if the last drink is B

    for a, b in zip(energyDrinkA, energyDrinkB):
      dpA, dpB = max(dpB, dpA + a), max(dpA, dpB + b)

    return max(dpA, dpB)
