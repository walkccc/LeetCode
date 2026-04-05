class Solution {
  public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy,
                              int[] experience) {
    return getRequiredEnergy(initialEnergy, energy) +
        getRequiredExperience(initialExperience, experience);
  }

  private int getRequiredEnergy(int initialEnergy, int[] energy) {
    return Math.max(0, Arrays.stream(energy).sum() + 1 - initialEnergy);
  }

  private int getRequiredExperience(int currentExperience, int[] experience) {
    int requiredExperience = 0;
    for (final int e : experience) {
      if (e >= currentExperience) {
        requiredExperience += e + 1 - currentExperience;
        currentExperience += e + 1 - currentExperience;
      }
      currentExperience += e;
    }
    return requiredExperience;
  }
}
