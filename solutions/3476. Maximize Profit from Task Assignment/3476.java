class Solution {
  public long maxProfit(int[] workers, int[][] tasks) {
    long totalProfit = 0;
    int maxRemainingProfit = 0;
    Map<Integer, List<Integer>> skillToProfits = new HashMap<>();

    for (int[] task : tasks) {
      final int skill = task[0];
      final int profit = task[1];
      skillToProfits.computeIfAbsent(skill, k -> new ArrayList<>()).add(profit);
    }

    for (List<Integer> profits : skillToProfits.values())
      Collections.sort(profits, Collections.reverseOrder());

    for (final int workerSkill : workers)
      if (skillToProfits.containsKey(workerSkill) && !skillToProfits.get(workerSkill).isEmpty()) {
        final int profit = skillToProfits.get(workerSkill).get(0);
        skillToProfits.get(workerSkill).remove(0);
        totalProfit += profit;
      }

    for (List<Integer> profits : skillToProfits.values())
      if (!profits.isEmpty())
        maxRemainingProfit = Math.max(maxRemainingProfit, profits.get(0));

    return totalProfit + maxRemainingProfit;
  }
}
