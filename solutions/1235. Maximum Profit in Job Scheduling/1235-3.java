class Job {
  public int startTime;
  public int endTime;
  public int profit;
  public Job(int startTime, int endTime, int profit) {
    this.startTime = startTime;
    this.endTime = endTime;
    this.profit = profit;
  }
}

class Solution {
  public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
    final int n = startTime.length;

    Job[] jobs = new Job[n];

    for (int i = 0; i < n; ++i)
      jobs[i] = new Job(startTime[i], endTime[i], profit[i]);

    Arrays.sort(jobs, (a, b) -> a.startTime - b.startTime);

    // will use binary search to find the first available startTime
    for (int i = 0; i < n; ++i)
      startTime[i] = jobs[i].startTime;

    return getMaxProfit(jobs);
  }

  private int getMaxProfit(Job[] jobs) {
    int maxProfit = 0;
    PriorityQueue<Job> pq = new PriorityQueue<>((a, b) -> a.endTime - b.endTime);

    for (Job job : jobs) {
      while (!pq.isEmpty() && job.startTime >= pq.peek().endTime)
        maxProfit = Math.max(maxProfit, pq.poll().profit);
      pq.offer(new Job(job.startTime, job.endTime, job.profit + maxProfit));
    }

    while (!pq.isEmpty())
      maxProfit = Math.max(maxProfit, pq.poll().profit);

    return maxProfit;
  }
}
