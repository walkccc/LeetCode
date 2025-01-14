class Solution {
  public int maxEvents(int[][] events) {
    int ans = 0;
    int d = 0; // the current day
    int i = 0; // events' index
    Queue<Integer> minHeap = new PriorityQueue<>();

    Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));

    while (!minHeap.isEmpty() || i < events.length) {
      // If no events are available to attend today, let time flies to the next
      // available event.
      if (minHeap.isEmpty())
        d = events[i][0];
      // All the events starting from today are newly available.
      while (i < events.length && events[i][0] == d)
        minHeap.offer(events[i++][1]);
      // Greedily attend the event that'll end the earliest since it has higher
      // chance can't be attended in the future.
      minHeap.poll();
      ++ans;
      ++d;
      // Pop the events that can't be attended.
      while (!minHeap.isEmpty() && minHeap.peek() < d)
        minHeap.poll();
    }

    return ans;
  }
}
