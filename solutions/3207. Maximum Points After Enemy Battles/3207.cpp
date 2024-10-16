class Solution {
 public:
  long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
    const int minEnergy = ranges::min(enemyEnergies);
    return currentEnergy < minEnergy
               ? 0
               : (currentEnergy +
                  accumulate(enemyEnergies.begin(), enemyEnergies.end(), 0LL) -
                  minEnergy) /
                     minEnergy;
  }
};
