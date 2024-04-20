class Solution:
  def maximumPopulation(self, logs: List[List[int]]) -> int:
    kMinYear = 1950
    kMaxYear = 2050
    ans = 0
    maxPopulation = 0
    runningPopulation = 0
    # population[i] := the population of year i
    population = [0] * (kMaxYear + 1)

    for birth, death in logs:
      population[birth] += 1
      population[death] -= 1

    for year in range(kMinYear, kMaxYear + 1):
      runningPopulation += population[year]
      if runningPopulation > maxPopulation:
        maxPopulation = runningPopulation
        ans = year

    return ans
