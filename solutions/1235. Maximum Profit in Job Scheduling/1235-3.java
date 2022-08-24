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
    Queue<Job> minHeap = new PriorityQueue<>((a, b) -> a.endTime - b.endTime);

    for (Job job : jobs) {
      while (!minHeap.isEmpty() && job.startTime >= minHeap.peek().endTime)
        maxProfit = Math.max(maxProfit, minHeap.poll().profit);
      minHeap.offer(new Job(job.startTime, job.endTime, job.profit + maxProfit));
    }

    while (!minHeap.isEmpty())
      maxProfit = Math.max(maxProfit, minHeap.poll().profit);

    return maxProfit;
  }
}
