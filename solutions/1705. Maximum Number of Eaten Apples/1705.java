class Solution {
  public int eatenApples(int[] apples, int[] days) {
    final int n = apples.length;
    int ans = 0;
    // (the rotten day, the number of apples)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());

    for (int i = 0; i < n || !minHeap.isEmpty(); ++i) {
      // Remove the rotten apples.
      while (!minHeap.isEmpty() && minHeap.peek().getKey() <= i)
        minHeap.poll();
      // Add today's apples.
      if (i < n && apples[i] > 0)
        minHeap.offer(new Pair<>(i + days[i], apples[i]));
      // Eat one apple today.
      if (!minHeap.isEmpty()) {
        final int rottenDay = minHeap.peek().getKey();
        final int numApples = minHeap.poll().getValue();
        if (numApples > 1)
          minHeap.offer(new Pair<>(rottenDay, numApples - 1));
        ++ans;
      }
    }

    return ans;
  }
}
