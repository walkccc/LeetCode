class Solution {
 public:
  long long maxEnergyBoost(vector<int>& energyDrinkA,
                           vector<int>& energyDrinkB) {
    long dpA = 0;  // the maximum energy boost if the last drink is A
    long dpB = 0;  // the maximum energy boost if the last drink is B

    for (int i = 0; i < energyDrinkA.size(); ++i) {
      const long newDpA = max(dpB, dpA + energyDrinkA[i]);
      const long newDpB = max(dpA, dpB + energyDrinkB[i]);
      dpA = newDpA;
      dpB = newDpB;
    }

    return max(dpA, dpB);
  }
};
