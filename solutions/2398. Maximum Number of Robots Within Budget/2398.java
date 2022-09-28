class Solution {
  public int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
    long cost = 0;
    // max queue storing chargeTimes[i]
    Deque<Integer> q = new ArrayDeque<>();

    int j = 0; // window's range := [i..j], so k = i - j + 1
    for (int i = 0; i < chargeTimes.length; ++i) {
      cost += runningCosts[i];
      while (!q.isEmpty() && q.peekLast() < chargeTimes[i])
        q.pollLast();
      q.offerLast(chargeTimes[i]);
      if (q.peekFirst() + (i - j + 1) * cost > budget) {
        if (q.peekFirst() == chargeTimes[j])
          q.pollFirst();
        cost -= runningCosts[j++];
      }
    }

    return chargeTimes.length - j;
  }
}
