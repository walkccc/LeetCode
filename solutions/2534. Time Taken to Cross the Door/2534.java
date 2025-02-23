class Solution {
  public int[] timeTaken(int[] arrival, int[] state) {
    final int n = arrival.length;
    int[] ans = new int[n];
    Queue<Integer>[] qs = new Queue[2];
    qs[0] = new LinkedList<>(); // enter queue
    qs[1] = new LinkedList<>(); // exit queue

    for (int i = 0; i < n; ++i) {
      popQueues(arrival[i], qs, ans);
      // If the door was not used in the previous second, then the person who
      // wants to exit goes first.
      if (arrival[i] > time) {
        time = arrival[i]; // Forward `time` to now.
        d = 1;             // Reset priority to exit.
      }
      qs[state[i]].offer(i);
    }

    popQueues(200000, qs, ans);
    return ans;
  }

  private int time = 0;
  private int d = 1; // 0: enter, 1: exit

  private void popQueues(int arrivalTime, Queue<Integer>[] qs, int[] ans) {
    while (arrivalTime > time && (!qs[0].isEmpty() || !qs[1].isEmpty())) {
      if (qs[d].isEmpty())
        d ^= 1; // Toggle between enter (0) and exit (1)
      ans[qs[d].poll()] = time++;
    }
  }
}
