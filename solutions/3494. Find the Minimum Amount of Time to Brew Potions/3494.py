class Solution:
  def minTime(self, skill: list[int], mana: list[int]) -> int:
    sumSkill = sum(skill)
    prevWizardDone = sumSkill * mana[0]

    for j in range(1, len(mana)):
      prevPotionDone = prevWizardDone
      for i in range(len(skill) - 2, -1, -1):
        # start time for wizard i brewing potion j
        # = max(end time for wizard i brewing potion j - 1,
        #       the earliest start time for wizard i + 1 brewing potion j
        #       (coming from previous iteration)
        #       - time for wizard i brewing potion j)
        prevPotionDone -= skill[i + 1] * mana[j - 1]
        prevWizardDone = max(prevPotionDone,
                             prevWizardDone - skill[i] * mana[j])
      prevWizardDone += sumSkill * mana[j]

    return prevWizardDone
