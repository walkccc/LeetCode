class Solution {
 public:
  int minNumberOfHours(int initialEnergy, int initialExperience,
                       vector<int>& energy, vector<int>& experience) {
    return getRequiredEnergy(initialEnergy, energy) +
           getRequiredExperience(initialExperience, experience);
  }

 private:
  int getRequiredEnergy(int initialEnergy, const vector<int>& energy) {
    return max(0,
               accumulate(energy.begin(), energy.end(), 0) + 1 - initialEnergy);
  }

  int getRequiredExperience(int currentExperience,
                            const vector<int>& experience) {
    int requiredExperience = 0;
    for (const int e : experience) {
      if (e >= currentExperience) {
        requiredExperience += e + 1 - currentExperience;
        currentExperience += e + 1 - currentExperience;
      }
      currentExperience += e;
    }
    return requiredExperience;
  }
};
