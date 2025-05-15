class Solution {
  public long minTime(int[] skill, int[] mana) {
    long sumSkill = Arrays.stream(skill).sum();
    long prevWizardDone = sumSkill * mana[0];

    for (int j = 1; j < mana.length; ++j) {
      long prevPotionDone = prevWizardDone;
      for (int i = skill.length - 2; i >= 0; --i) {
        // start time for wizard i brewing potion j
        // = max(end time for wizard i brewing potion j - 1,
        //       the earliest start time for wizard i + 1 brewing potion j
        //       (coming from previous iteration)
        //       - time for wizard i brewing potion j)
        prevPotionDone -= (long) skill[i + 1] * mana[j - 1];
        prevWizardDone = Math.max(prevPotionDone, prevWizardDone - (long) skill[i] * mana[j]);
      }
      prevWizardDone += sumSkill * mana[j];
    }

    return prevWizardDone;
  }
}
