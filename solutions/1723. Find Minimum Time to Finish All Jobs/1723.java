class Solution {
  public int minimumTimeRequired(int[] jobs, int k) {
    ans = Arrays.stream(jobs).sum();
    int[] times = new int[k];

    Arrays.sort(jobs);
    Collections.reverse(Arrays.asList(jobs));
    dfs(jobs, 0, times);
    return ans;
  }

  private int ans = 0;

  private void dfs(int[] jobs, int s, int[] times) {
    if (s == jobs.length) {
      ans = Math.min(ans, Arrays.stream(times).max().getAsInt());
      return;
    }
    for (int i = 0; i < times.length; ++i) {
      if (times[i] + jobs[s] >= ans)
        continue;
      times[i] += jobs[s];
      dfs(jobs, s + 1, times);
      times[i] -= jobs[s];
      if (times[i] == 0)
        return;
    }
  }
}
