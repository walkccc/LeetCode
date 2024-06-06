class Solution:
  def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
    return self._getRequiredEnergy(initialEnergy, energy) + \
        self._getRequiredExperience(initialExperience, experience)

  def _getRequiredEnergy(self, initialEnergy: int, energy: List[int]) -> int:
    return max(0, sum(energy) + 1 - initialEnergy)

  def _getRequiredExperience(self, currentExperience: int, experience: List[int]) -> int:
    requiredExperience = 0
    for e in experience:
      if e >= currentExperience:
        requiredExperience += e + 1 - currentExperience
        currentExperience += e + 1 - currentExperience
      currentExperience += e
    return requiredExperience
