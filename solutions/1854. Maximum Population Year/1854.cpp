class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    constexpr int kMinYear = 1950;
    constexpr int kMaxYear = 2050;
    int ans = 0;
    int maxPopulation = 0;
    int runningPopulation = 0;
    // population[i] := the population of year i
    vector<int> population(kMaxYear + 1);

    for (const vector<int>& log : logs) {
      const int birth = log[0];
      const int death = log[1];
      ++population[birth];
      --population[death];
    }

    for (int year = kMinYear; year <= kMaxYear; ++year) {
      runningPopulation += population[year];
      if (runningPopulation > maxPopulation) {
        maxPopulation = runningPopulation;
        ans = year;
      }
    }

    return ans;
  }
};
