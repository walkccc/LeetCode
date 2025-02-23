class Solution:
  def maximumPoints(self, enemyEnergies: list[int], currentEnergy: int) -> int:
    minEnergy = min(enemyEnergies)
    return (0 if currentEnergy < minEnergy
            else (currentEnergy + sum(enemyEnergies) - minEnergy) // minEnergy)
