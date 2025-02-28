class Solution {
  public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
    long dpA = 0; // the maximum energy boost if the last drink is A
    long dpB = 0; // the maximum energy boost if the last drink is B

    for (int i = 0; i < energyDrinkA.length; ++i) {
      final long newDpA = Math.max(dpB, dpA + energyDrinkA[i]);
      final long newDpB = Math.max(dpA, dpB + energyDrinkB[i]);
      dpA = newDpA;
      dpB = newDpB;
    }

    return Math.max(dpA, dpB);
  }
}
