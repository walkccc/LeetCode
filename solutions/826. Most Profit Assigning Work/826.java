class Solution {
  public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
    int ans = 0;
    List<Pair<Integer, Integer>> jobs = new ArrayList<>();

    for (int i = 0; i < difficulty.length; ++i)
      jobs.add(new Pair<>(difficulty[i], profit[i]));

    Collections.sort(jobs, Comparator.comparing(Pair::getKey));
    Arrays.sort(worker);

    int i = 0;
    int maxProfit = 0;

    for (final int w : worker) {
      for (; i < jobs.size() && w >= jobs.get(i).getKey(); ++i)
        maxProfit = Math.max(maxProfit, jobs.get(i).getValue());
      ans += maxProfit;
    }

    return ans;
  }
}
