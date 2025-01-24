class Solution {
  public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
    final int minEnergy = Arrays.stream(enemyEnergies).min().orElse(0);
    return currentEnergy < minEnergy
        ? 0
        : (currentEnergy + Arrays.stream(enemyEnergies).asLongStream().sum() - minEnergy) /
              minEnergy;
  }
}
