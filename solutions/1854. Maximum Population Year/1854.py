class Solution:
  def maximumPopulation(self, logs: list[list[int]]) -> int:
    MIN_YEAR = 1950
    MAX_YEAR = 2050
    ans = 0
    maxPopulation = 0
    runningPopulation = 0
    # population[i] := the population of year i
    population = [0] * (MAX_YEAR + 1)

    for birth, death in logs:
      population[birth] += 1
      population[death] -= 1

    for year in range(MIN_YEAR, MAX_YEAR + 1):
      runningPopulation += population[year]
      if runningPopulation > maxPopulation:
        maxPopulation = runningPopulation
        ans = year

    return ans
