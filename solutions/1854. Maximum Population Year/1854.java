class Solution {
  public int maximumPopulation(int[][] logs) {
    final int MIN_YEAR = 1950;
    final int MAX_YEAR = 2050;
    int ans = 0;
    int maxPopulation = 0;
    int runningPopulation = 0;
    // population[i] := the population of year i
    int[] population = new int[MAX_YEAR + 1];

    for (int[] log : logs) {
      final int birth = log[0];
      final int death = log[1];
      ++population[birth];
      --population[death];
    }

    for (int year = MIN_YEAR; year <= MAX_YEAR; ++year) {
      runningPopulation += population[year];
      if (runningPopulation > maxPopulation) {
        maxPopulation = runningPopulation;
        ans = year;
      }
    }

    return ans;
  }
}
