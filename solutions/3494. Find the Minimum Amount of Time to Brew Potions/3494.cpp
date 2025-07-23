class Solution {
 public:
  long long minTime(vector<int>& skill, vector<int>& mana) {
    long sumSkill = accumulate(skill.begin(), skill.end(), 0L);
    long prevWizardDone = sumSkill * mana[0];

    for (int j = 1; j < mana.size(); ++j) {
      long prevPotionDone = prevWizardDone;
      for (int i = skill.size() - 2; i >= 0; --i) {
        // start time for wizard i brewing potion j
        // = max(end time for wizard i brewing potion j - 1,
        //       the earliest start time for wizard i + 1 brewing potion j
        //       (coming from previous iteration)
        //       - time for wizard i brewing potion j)
        prevPotionDone -= static_cast<long>(skill[i + 1]) * mana[j - 1];
        prevWizardDone =
            max(prevPotionDone,
                prevWizardDone - static_cast<long>(skill[i]) * mana[j]);
      }
      prevWizardDone += sumSkill * mana[j];
    }

    return prevWizardDone;
  }
};
